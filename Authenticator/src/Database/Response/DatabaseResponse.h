#pragma once
#include "pch.h"

namespace Database::Response {
	enum class Status {
		OK, Failed
	};

	enum class FailureReason {

	};

	class DatabaseResponse {
	public:
		void SetStatus(Status status);
		Status GetStatus() const;

		void SetFailureReason(FailureReason reason);
		FailureReason GetFailureReason() const;


	private:
		class Impl;

		std::unique_ptr<Impl> impl;

		DatabaseResponse();
		~DatabaseResponse();
	};

	std::string FailureReasonToString(FailureReason reason) {
		switch (reason) {

			default: return "Invalid failure reason.";
		}
	}
}