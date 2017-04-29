#include "Errors.hpp"

RunTimeErrorController::RunTimeErrorController(std::string const &message) : std::runtime_error::runtime_error(message), _message(message) {
}

RunTimeErrorController::RunTimeErrorController(const char *message) : std::runtime_error::runtime_error(message), _message(message) {
}

RunTimeErrorModel::RunTimeErrorModel(std::string const &message) : std::runtime_error::runtime_error(message), _message(message) {
}

RunTimeErrorModel::RunTimeErrorModel(const char *message) : std::runtime_error::runtime_error(message), _message(message) {
}

RunTimeErrorView::RunTimeErrorView(std::string const &message) : std::runtime_error::runtime_error(message), _message(message) {
}

RunTimeErrorView::RunTimeErrorView(const char *message) : std::runtime_error::runtime_error(message), _message(message) {
}