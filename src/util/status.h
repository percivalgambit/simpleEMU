#ifndef UTIL_STATUS_H_
#define UTIL_STATUS_H_

// Copied from https://github.com/google/lmctfy/blob/master/util/task/status.h

#include <ostream>
#include <string>

namespace util {

class Status {
 public:
  enum class Code {
    kOK = 0,
    kOutOfBounds,
    kIsHalted,
    kInvalid,
  };

  static const Status& OK;

  Status();
  Status(const Status::Code code);
  Status(const Status::Code code, const std::string& message);

  bool operator==(const Status& x) const;
  bool operator!=(const Status& x) const;

  bool IsOk() const;
  Status::Code StatusCode() const;
  const std::string& Message() const;

  std::string ToString() const;

 private:
  Status::Code code_;
  std::string message_;
};

std::ostream& operator<<(std::ostream& os, const Status& status);

}  // namespace util

#endif  // UTIL_STATUS_H_