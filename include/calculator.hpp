#ifndef B31A80AB_5724_4C6A_81ED_F301F749F738
#define B31A80AB_5724_4C6A_81ED_F301F749F738

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <exception>
#include <iomanip>
#include <numeric>
#include <stdexcept>
#include <vector>

class Function {
public:
  enum Type : uint8_t {
    Polynomial,
    Exponential,
    Logarithmic,
    Power,
  };
  explicit Function(Type type, int m) : m(m), type(type) {}
  explicit Function(Type type) : m(0), type(type) {}
  int get_m() const {
    if (type == Polynomial) {
      return m;
    }
    throw std::invalid_argument("Cannot get m for not polynomial function");
  }

  Type get_type() const { return type; }

  std::string
  get_polynomial_string(const std::vector<double> &coefficients) const {
    std::stringstream ss;
    bool first = true;
    for (int i = static_cast<int>(coefficients.size()) - 1; i >= 0; --i) {
      double coef = coefficients[i];
      if (coef != 0.0 || (i == 0 && coefficients.size() == 1)) {
        if (!first) {
          ss << (coef >= 0.0 ? "+" : "-");
        }
        ss << std::fixed << std::setprecision(4) << std::abs(coef);
        if (i > 0) {
          ss << "x";
          if (i > 1) {
            ss << "^" << i;
          }
        }
        first = false;
      }
    }
    if (first) {
      ss << "0";
    }
    return ss.str();
  }

  std::string
  get_exponential_string(const std::vector<double> &coefficients) const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << coefficients[0] << R"(*\\exp()"
       << coefficients[1] << "x"
       << ")";
    return ss.str();
  }

  std::string
  get_logarithmic_string(const std::vector<double> &coefficients) const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << coefficients[0] << " + "
       << coefficients[1] << R"(*\\ln(x))";
    return ss.str();
  }

  std::string get_power_string(const std::vector<double> &coefficients) const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << coefficients[0] << "x^"
       << coefficients[1];
    return ss.str();
  }

  std::string get_string_function(const std::vector<double> &coefficients) {
    switch (type) {
    case Function::Type::Polynomial:
      return get_polynomial_string(coefficients);
    case Function::Type::Exponential:
      return get_exponential_string(coefficients);
    case Function::Type::Logarithmic:
      return get_logarithmic_string(coefficients);
    case Function::Type::Power:
      return get_power_string(coefficients);
    default:
      throw std::invalid_argument("Unknown function type");
    }
  }

  std::string to_string() const {
    switch (type) {
    case Polynomial:
      return "Polynomial(" + std::to_string(m) + ")";
    case Exponential:
      return "Exponential";
    case Logarithmic:
      return "Logarithmic";
    case Power:
      return "Power";
    }
    throw std::invalid_argument("Unknown function type");
  }

private:
  int m;
  Type type;
};

class ApproximationCalculator {
private:
  Function function;
  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> coefficients;
  constexpr static double ACC = 1e-4;

  static double get_function_value(Function func,
                                   std::vector<double> const &coefficients,
                                   double x) {
    switch (func.get_type()) {
    case Function::Type::Polynomial: {
      double sum = 0.0;
      for (int i = 0; i < func.get_m(); ++i) {
        sum += coefficients[i] * pow(x, i);
      }
      return sum;
    }
    case Function::Type::Exponential:
      return coefficients[0] * exp(coefficients[1] * x);
    case Function::Type::Logarithmic:
      return coefficients[0] + coefficients[1] * log(x);
    case Function::Type::Power:
      return coefficients[0] * pow(x, coefficients[1]);
    default:
      throw std::invalid_argument("Unsupported function");
    }
  }

  static std::vector<double>
  linear_interpolation(int n, std::vector<std::vector<double>> &a,
                       std::vector<double> const &b, double e) {
    std::vector<double> v_x(n, 0.0);
    while (true) {
      auto delta = 0.0;
      for (int i = 0; i < n; ++i) {
        auto s = 0.0;
        for (int j = 0; j < i; ++j) {
          s += a[i][j] * v_x[j];
        }
        for (int j = i + 1; j < n; ++j) {
          s += a[i][j] * v_x[j];
        }
        auto x_new = (b[i] - s) / a[i][i];
        if (auto d = std::fabs(x_new - v_x[i]); d > delta) {
          delta = d;
        }
        v_x[i] = x_new;
      }
      if (delta < e) {
        break;
      }
    }
    return v_x;
  }

  static std::vector<double>
  approximation_calculation(Function func, int n, std::vector<double> const &x,
                            std::vector<double> const &y) {
    switch (func.get_type()) {
    case Function::Type::Polynomial: {
      std::vector<double> b(func.get_m() + 1, 0.0);
      std::vector<std::vector<double>> matrix(
          func.get_m() + 1, std::vector<double>(func.get_m() + 1, 0.0));
      for (int i = 0; i <= func.get_m(); ++i) {
        for (int j = 0; j < n; ++j) {
          b[i] += std::pow(x[j], i) * y[j];
        }
      }
      for (int i = 0; i <= func.get_m(); ++i) {
        for (int j = 0; j <= func.get_m(); ++j) {
          auto val = 0.0;
          for (auto &&xi : x) {
            val += std::pow(xi, i + j);
          }
          matrix[i][j] = val;
        }
      }
      return linear_interpolation(func.get_m() + 1, matrix, b, ACC);
    }
    case Function::Type::Exponential: {
      std::vector<double> lny;
      lny.reserve(y.size());
      for (auto &&yi : y) {
        lny.push_back(std::log(yi));
      }
      auto a = approximation_calculation(
          Function(Function::Type::Polynomial, 1), n, x, lny);
      a[0] = std::exp(a[0]);
      return a;
    }
    case Function::Type::Power: {
      std::vector<double> lnx;
      lnx.reserve(x.size());
      std::vector<double> lny;
      lny.reserve(y.size());
      return approximation_calculation(Function(Function::Type::Polynomial, 1),
                                       n, lnx, lny);
    }

    case Function::Type::Logarithmic: {
      std::vector<double> lnx;
      lnx.reserve(x.size());
      return approximation_calculation(Function(Function::Type::Polynomial, 1),
                                       n, lnx, y);
    }
    }
    return {};
  }

  static std::vector<double> differences_calculation(
      Function f, int n, std::vector<double> const &coefficients,
      std::vector<double> const &x, std::vector<double> const &y) {
    std::vector<double> diff(n, 0.0);

    for (int i = 0; i < n; ++i) {
      diff[i] = y[i] - get_function_value(f, coefficients, x[i]);
    }

    return diff;
  }

  static double standard_deviation_calculation(std::vector<double> const &diffs,
                                               int n) {
    double sum = 0.0;
    for (auto &&diff : diffs) {
      sum += diff * diff;
    }
    return std::sqrt(sum / n);
  }

public:
  ApproximationCalculator(Function func, std::vector<double> const &x,
                          std::vector<double> const &y)
      : function(func), x(x), y(y) {}

  static Function find_best_function(int n, std::vector<double> const &x,
                                     std::vector<double> const &y) {
    std::vector<std::pair<double, Function>> deviations;

    // Polynomial of degree 1 to 3
    for (int i = 1; i <= 3; ++i) {
      auto func = Function(Function::Type::Polynomial, i);
      auto approx = approximation_calculation(func, n, x, y);
      auto differences = differences_calculation(func, n, approx, x, y);
      auto deviation = standard_deviation_calculation(differences, n);
      deviations.push_back({deviation, func});
    }

    // Exponential
    {
      auto func = Function(Function::Type::Exponential);
      auto approximations = approximation_calculation(func, n, x, y);
      auto differences = differences_calculation(func, n, approximations, x, y);
      auto deviation = standard_deviation_calculation(differences, n);
      deviations.push_back({deviation, func});
    }

    // Logarithmic
    {
      auto func = Function(Function::Type::Logarithmic);
      auto approximations = approximation_calculation(func, n, x, y);
      auto differences = differences_calculation(func, n, approximations, x, y);
      auto deviation = standard_deviation_calculation(differences, n);
      deviations.push_back({deviation, func});
    }

    // Power
    {
      auto func = Function(Function::Type::Power);
      auto approximations = approximation_calculation(func, n, x, y);
      auto differences = differences_calculation(func, n, approximations, x, y);
      auto deviation = standard_deviation_calculation(differences, n);
      deviations.push_back({deviation, func});
    }

    std::sort(deviations.begin(), deviations.end(),
              [](const auto &a, const auto &b) {
                return std::get<0>(a) < std::get<0>(b);
              });
    return std::get<1>(deviations[0]);
  }

  std::pair<double, std::string> calculate_pearson_correlation() {
    auto n = this->x.size();
    auto sum_x = std::accumulate(x.begin(), x.end(), 0.0);
    auto sum_y = std::accumulate(y.begin(), y.end(), 0.0);
    auto sum_xy = 0.0;
    for (int i = 0; i < n; ++i) {
      sum_xy += x[i] * y[i];
    }
    auto sum_x_squared = 0.0;
    auto sum_y_squared = 0.0;
    for (int i = 0; i < n; ++i) {
      sum_x_squared += pow(x[i], 2);
      sum_y_squared += pow(y[i], 2);
    }

    auto numerator = static_cast<double>(n) * sum_xy - sum_x * sum_y;
    auto denominator =
        std::sqrt((static_cast<double>(n) * sum_x_squared - sum_x * sum_x) *
                  (static_cast<double>(n) * sum_y_squared - sum_y * sum_y));
    if (denominator == 0.0) {
      return {0.0, "Division by zero"};
    }
    auto r = numerator / denominator;
    if (std::fabs(r) < 0.8) {
      return {0.0, "No strong linear dependency detected."};
    }

    return {r, ""};
  }

  std::vector<double> get_phi_values() const {
    std::vector<double> phi_values;
    phi_values.reserve(x.size());
    for (auto const &xi : x) {
      phi_values.push_back(get_function_value(function, coefficients, xi));
    }
    return phi_values;
  }

  std::vector<double> get_epsilon_values() const {
    std::vector<double> epsilon_values;
    epsilon_values.reserve(x.size());
    for (int i = 0; i < x.size(); ++i) {
      epsilon_values.push_back(
          y[i] - get_function_value(function, coefficients, x[i]));
    }
    return epsilon_values;
  }

  std::vector<double> calculate_coefficients() {
    coefficients =
        approximation_calculation(function, static_cast<int>(x.size()), x, y);
    return coefficients;
  }
};

#endif /* B31A80AB_5724_4C6A_81ED_F301F749F738 */
