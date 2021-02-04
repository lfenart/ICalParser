module Parser;

import std.core;
import std.regex;
import Exception;

namespace parser {

const ast::NodeFactory& Parser::get_factory() const
{
	return factory;
}

std::optional<PropertyHelper> Parser::read_tokens(std::istream& input) const
{
	std::regex re(R"(([^;:]*)((?:;[^=]*=\"[^"]*\"|;[^=]*[^;:]*)*):(.*))",
		std::regex_constants::ECMAScript);
	std::string line;
	if (!std::getline(input, line)) {
		return std::nullopt;
	}
	int c = input.get();
	while (c == ' ' || c == '\t') {
		std::string next_line;
		std::getline(input, next_line);
		line += next_line;
		c = input.get();
	}
	input.unget();
	std::smatch matchs;
	std::regex_search(line, matchs, re);
	std::string name = matchs[1];
	std::string params_raw = matchs[2];
	std::string value = matchs[3];
	std::regex re_param(R"(;([^=]*)=(\"(?:[^"]*)\"|(?:[^;]*))(;.*)?)", std::regex_constants::ECMAScript);
	std::map<std::string, std::string> params;
	while (params_raw.size() > 0) {
		std::regex_search(params_raw, matchs, re_param);
		params[matchs[1]] = matchs[2];
		params_raw = matchs[3];
	}
	return PropertyHelper(name, value, params);
}

void Parser::parse_unknown_component(std::istream& input, const std::string& name) const
{
	for (;;) {
		auto prop = read_tokens(input);
		if (!prop.has_value()) {
			throw exception::UnexpectedEofError();
		}
		std::string token1 = prop->get_name();
		std::string token2 = prop->get_value();
		if (token1 == "END") {
			if (token2 != name) {
				throw exception::UnexpectedComponentEndError(token2);
			}
			return;
		}
		if (token1 == "BEGIN") {
			parse_unknown_component(input, token2);
		}
	}
}

}
