#include "catch.hpp"

#include "util/status.h"
#include "util/statusor.h"

using util::Status;
using util::StatusOr;

TEST_CASE("StatusOr objects can contain values") {
  StatusOr<int> statusor(3);

  REQUIRE(statusor.GetStatus() == Status::OK);
  REQUIRE(statusor.IsOk());
  REQUIRE(statusor.ValueOrDie() == 3);
}

TEST_CASE("StatusOr objects can contain statuses") {
  Status status(Status::Code::kInvalid);
  StatusOr<int> statusor(status);

  REQUIRE(statusor.GetStatus() == status);
  REQUIRE_FALSE(statusor.IsOk());
  // TODO: Add test for ValueOrDie
}

TEST_CASE("StatusOr objects can be converted to other types") {
  StatusOr<int> statusor(4);
  StatusOr<double> converted(statusor);

  REQUIRE(converted.GetStatus() == Status::OK);
  REQUIRE(converted.IsOk());
  REQUIRE(converted.ValueOrDie() == Approx(4.0));

  Status status(Status::Code::kInvalid);
  StatusOr<int> statusor_status(status);
  StatusOr<double> converted_status(statusor_status);

  REQUIRE(converted_status.GetStatus() == status);
  REQUIRE_FALSE(converted_status.IsOk());
  // TODO: Add test for ValueOrDie
}