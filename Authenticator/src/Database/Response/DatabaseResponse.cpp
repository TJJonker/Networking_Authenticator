#include "pch.h"
#include "DatabaseResponse.h"

namespace Database::Response {
	void DatabaseResponse::SetStatus(Status status)
	{
		m_Status = status;
	}

	Status DatabaseResponse::GetStatus() const
	{
		return m_Status;
	}

	void DatabaseResponse::SetFailureReason(FailureReason reason)
	{
		m_Status = Status::Failed;
		m_Reason = reason;
	}

	FailureReason DatabaseResponse::GetFailureReason() const
	{
		return m_Reason;
	}

	void DatabaseResponse::SetResult(sql::ResultSet* result)
	{
		m_Result = result;
	}

	sql::ResultSet* DatabaseResponse::GetResult() const
	{
		return m_Result;
	}

	void DatabaseResponse::SetData(std::string data)
	{
		m_Data = data;
	}

	std::string DatabaseResponse::GetData() const
	{
		return m_Data;
	}
}