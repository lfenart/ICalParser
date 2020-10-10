export module Ast;

import std.core;

namespace ast {

export class Node;
export class NodeICal;
export class VCalendar;
export class VComponent;
export class NodeUnknownComponent;

class Node {
public:
	virtual ~Node() = default;
};

class NodeICal : public Node {
public:
	NodeICal() = default;
	virtual ~NodeICal() = default;

	const std::vector<std::unique_ptr<VCalendar>>& get_calendars() const;
	void add_calendar(std::unique_ptr<VCalendar>);

private:
	std::vector<std::unique_ptr<VCalendar>> calendars;
};

class VCalendar : public Node {
public:
	VCalendar() = default;
	virtual ~VCalendar() = default;

	const std::vector<std::unique_ptr<VComponent>>& get_components() const;

private:
	std::vector<std::unique_ptr<VComponent>> components;
};

class VComponent : public Node {
public:
	virtual ~VComponent() = default;

	const std::vector<std::unique_ptr<VComponent>>& get_components() const;

private:
	std::vector<std::unique_ptr<VComponent>> components;
};

}
