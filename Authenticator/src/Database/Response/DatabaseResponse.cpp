#include "pch.h"
#include "DatabaseResponse.h"

namespace Database::Response {
	class DatabaseResponse::Impl {
	private:
		Status m_Status;
		FailureReason m_Reason;

	public:
		void SetStatus(Status status) { m_Status = status; }
		Status GetStatus() const { return m_Status; }

		void SetFailureReason(FailureReason reason) { m_Reason = reason; }
		FailureReason GetFailureReason() const { return m_Reason; }
	};



	void DatabaseResponse::SetStatus(Status status) { impl->SetStatus(status); }

	Status DatabaseResponse::GetStatus() const { return impl->GetStatus(); }

	void DatabaseResponse::SetFailureReason(FailureReason reason) { impl->SetFailureReason(reason); }

	FailureReason DatabaseResponse::GetFailureReason() const { return impl->GetFailureReason(); }

	DatabaseResponse::DatabaseResponse()
		: impl(std::make_unique<Impl>()) { }

	DatabaseResponse::~DatabaseResponse() = default;
}