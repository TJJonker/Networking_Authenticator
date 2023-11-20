#pragma once
#include "Database/Response/Status.h"
#include "Database/Response/FailureReason.h"

namespace Database::Response {
	class DatabaseResponse {
	public:
		void SetStatus(Status status);
		Status GetStatus() const;

		void SetFailureReason(FailureReason reason);
		FailureReason GetFailureReason() const;

		void SetResult(sql::ResultSet* result);
		sql::ResultSet* GetResult() const;

		void SetData(std::string data);
		std::string GetData() const;

	private:
		Status m_Status = Status::OK;
		FailureReason m_Reason = FailureReason::NONE;
		sql::ResultSet* m_Result;	
		std::string m_Data;
	};
}