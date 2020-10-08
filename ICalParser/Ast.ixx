export module Ast;

import std.core;

namespace ast {

export class Node;
export class NodeICal;
export class NodeCalendar;
export class NodeComponent;
export class NodeUnknownComponent;

class Node {
public:
	virtual ~Node() = default;
};

class NodeICal : public Node {
public:
	NodeICal() = default;
	virtual ~NodeICal() = default;

	const std::vector<std::unique_ptr<NodeCalendar>>& get_calendars() const;
	void add_calendar(std::unique_ptr<NodeCalendar>);

private:
	std::vector<std::unique_ptr<NodeCalendar>> calendars;
};

class NodeCalendar : public Node {
public:
	NodeCalendar() = default;
	virtual ~NodeCalendar() = default;

	const std::vector<std::unique_ptr<NodeComponent>>& get_components() const;

private:
	std::vector<std::unique_ptr<NodeComponent>> components;
};

class NodeComponent : public Node {
public:
	virtual ~NodeComponent() = default;

	const std::vector<std::unique_ptr<NodeComponent>>& get_components() const;

private:
	std::vector<std::unique_ptr<NodeComponent>> components;
};

}
