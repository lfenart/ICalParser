export module Exception;

import std.core;

namespace exception {

export class UnexpectedEofError : public std::runtime_error {
public:
	UnexpectedEofError();
	virtual ~UnexpectedEofError() = default;
};

export class MissingColonError : public std::runtime_error {
public:
	MissingColonError();
	virtual ~MissingColonError() = default;
};

export class UnexpectedComponentEndError : public std::runtime_error {
public:
	UnexpectedComponentEndError(std::string);
	virtual ~UnexpectedComponentEndError() = default;
};

}
