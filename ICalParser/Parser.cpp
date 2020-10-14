module Parser;

import std.core;

namespace parser {

const NodeFactory& Parser::get_factory() const
{
	return factory;
}

void Parser::parse_unknown_component(std::istream& input, const char* name) const
{
	for (;;) {
		std::string line;
		if (!std::getline(input, line)) {
			throw "eof";
		}
		auto pos = line.find(":");
		if (pos == std::string::npos) {
			std::cerr << "':' not found, skipping line" << std::endl;
		} else {
			std::string token1 = line.substr(0, pos);
			std::string token2 = line.substr(pos + 1);
			if (std::strcmp("END", token1.c_str()) == 0) {
				if (std::strcmp(name, token2.c_str()) == 0) {
					return;
				} else {
					throw "unexpected end";
				}
			}
			if (std::strcmp("BEGIN", token1.c_str()) == 0) {
				parse_unknown_component(input, token2.c_str());
			}
		}
	}
}

}
