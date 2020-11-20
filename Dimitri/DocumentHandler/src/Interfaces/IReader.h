#pragma once

namespace DocumentHandler {
	namespace Interfaces {
		class IReader {
		public:
			virtual std::vector<std::vector<int>> Read(const std::filesystem::path& path) = 0;
		};
	}
}