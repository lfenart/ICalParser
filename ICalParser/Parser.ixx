export module Parser;

import std.core;
import Ast;

export namespace parser {

class NodeFactory;
class Parser;
class ICalParser;
class CalendarParser;
class ComponentParser;
class UnknownComponentParser;

class NodeFactory {
public:
	std::unique_ptr<ast::NodeCalendar> create_node_calendar() const;
	std::unique_ptr<ast::NodeICal> create_node_ical() const;
};

class Parser {
public:
	virtual ~Parser() = default;

	virtual std::unique_ptr<ast::Node> parse(std::istream&) const = 0;

protected:
	const NodeFactory& get_factory() const;

private:
	NodeFactory factory;
};

class UnknownComponentParser {
public:
	void parse(std::istream&, const char*) const;
};

class ComponentParser : public Parser {
private:
	UnknownComponentParser unknownComponentParser;
};

class CalendarParser : public Parser {
public:
	CalendarParser() = default;
	virtual ~CalendarParser() = default;

	std::unique_ptr<ast::Node> parse(std::istream&) const override;

private:
	UnknownComponentParser unknownComponentParser;
};

class ICalParser : public Parser {
public:
	ICalParser() = default;
	virtual ~ICalParser() = default;

	std::unique_ptr<ast::Node> parse(std::istream&) const override;

private:
	CalendarParser calendarParser;
};

}
