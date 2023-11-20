#pragma once

namespace Networking::Response {
	class ServerResponse {
	public:
		void SetData(std::vector<std::string> data) { m_Data = data; }
		std::vector<std::string> GetData() const { return m_Data; }

	private:
		std::vector<std::string> m_Data;
	};
}