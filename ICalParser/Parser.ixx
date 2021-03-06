export module Parser;

import std.core;
import Ast;

namespace parser {

export class Parser;
export class ICalParser;
export class VCalendarParser;
export class ComponentParser;
export class UnknownComponentParser;
export class VEventParser;
export class VAlarmParser;

class PropertyHelper {
public:
	PropertyHelper(std::string, std::string, std::map<std::string, std::string>);

	std::string get_name() const;
	std::string get_value() const;
	std::map<std::string, std::string> get_parameters() const;

private:
	std::string name;
	std::string value;
	std::map<std::string, std::string> parameters;
};

class Parser {
public:
	virtual ~Parser() = default;

	virtual ast::Node::uptr parse(std::istream&) const = 0;

protected:
	const ast::NodeFactory& get_factory() const;
	void parse_unknown_component(std::istream&, const std::string&) const;
	std::optional<PropertyHelper> read_tokens(std::istream&) const;

private:
	ast::NodeFactory factory;
};

class ComponentParser : public Parser {
public:
	ast::Node::uptr parse(std::istream&) const override;

protected:
	const std::map<std::string, std::unique_ptr<ComponentParser>>& get_component_parsers() const;
	const std::set<std::string>& get_properties() const;
	void add_component_parser(std::string add, std::unique_ptr<ComponentParser> parser);
	void add_property(std::string);
	virtual const std::string get_name() const = 0;
	virtual ast::Component::uptr create_component() const = 0;

private:
	std::map<std::string, std::unique_ptr<ComponentParser>> component_parsers;
	std::set<std::string> properties;
};

class VCalendarParser : public ComponentParser {
public:
	VCalendarParser();
	virtual ~VCalendarParser() = default;

protected:
	const std::string get_name() const override;
	ast::Component::uptr create_component() const override;
};

class VEventParser : public ComponentParser {
public:
	VEventParser();
	virtual ~VEventParser() = default;

protected:
	const std::string get_name() const override;
	ast::Component::uptr create_component() const override;
};

class VAlarmParser : public ComponentParser {
public:
	VAlarmParser();
	virtual ~VAlarmParser() = default;

protected:
	const std::string get_name() const override;
	ast::Component::uptr create_component() const override;
};

class VJournalParser : public ComponentParser {
public:
	VJournalParser();
	virtual ~VJournalParser() = default;

protected:
	const std::string get_name() const override;
	ast::Component::uptr create_component() const override;
};

class ICalParser : public Parser {
public:
	ICalParser() = default;
	virtual ~ICalParser() = default;

	ast::Node::uptr parse(std::istream&) const override;

private:
	VCalendarParser calendar_parser;
};

}
