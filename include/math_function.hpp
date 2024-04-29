#ifndef E861E497_907A_4B3B_B012_A26997C6C307
#define E861E497_907A_4B3B_B012_A26997C6C307

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <vector>

/**
 * @brief The Function class represents different types of mathematical
 * functions.
 */
class Function {
public:
  enum Type : uint8_t {
    Polynomial,
    Exponential,
    Logarithmic,
    Power,
  };
  /**
   * @brief Constructs a Function object with the specified type and optional
   * parameter m.
   * @param type The type of the function.
   * @param m The parameter for polynomial functions.
   */
  Function(Type type, int m = 0) : m(m), type(type) {}

  /**
   * @brief Retrieves the parameter m for polynomial functions.
   * @return The parameter m if the function is polynomial.
   * @throw std::invalid_argument if the function is not polynomial.
   */
  int get_m() const {
    if (type == Polynomial) {
      return m;
    }
    throw std::invalid_argument("Cannot get m for not polynomial function");
  }

  /**
   * @brief Retrieves the type of the function.
   * @return The type of the function.
   */
  Type get_type() const { return type; }

  // Methods for getting string representations of different function types...

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

  std::string
  get_string_function(const std::vector<double> &coefficients) const {
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

  /**
   * @brief Converts the Function object to a string representation.
   * @return A string representation of the Function object.
   * @throw std::invalid_argument if the function type is unknown.
   */
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
  int m;     /**< The parameter m for polynomial functions. */
  Type type; /**< The type of the function. */
};

#endif /* E861E497_907A_4B3B_B012_A26997C6C307 */
