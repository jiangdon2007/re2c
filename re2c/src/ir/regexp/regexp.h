#ifndef _RE2C_IR_REGEXP_REGEXP_
#define _RE2C_IR_REGEXP_REGEXP_

#include "src/util/c99_stdint.h"
#include <set>
#include <string>
#include <vector>

#include "src/conf/warn.h"
#include "src/ir/rule.h"
#include "src/util/free_list.h"
#include "src/util/range.h"

namespace re2c
{

struct Opt;

struct RegExp
{
	static free_list<RegExp*> flist;
	static const uint32_t MANY;

	enum type_t {NIL, SYM, ALT, CAT, ITER, TAG, CAP, REF} type;
	union
	{
		const Range *sym;
		struct
		{
			const RegExp *re1;
			const RegExp *re2;
		} alt;
		struct
		{
			const RegExp *re1;
			const RegExp *re2;
		} cat;
		struct
		{
			const RegExp *re;
			uint32_t min;
			uint32_t max;
		} iter;
		const std::string *tag;
		const RegExp *cap;
		struct
		{
			const RegExp *re;
			const std::string *name;
		} ref;
	};
	uint32_t line;
	uint32_t column;

	static const RegExp *make_nil(uint32_t l, uint32_t c)
	{
		return new RegExp(l, c, NIL);
	}
	static const RegExp *make_sym(uint32_t l, uint32_t c, const Range *r)
	{
		RegExp *re = new RegExp(l, c, SYM);
		re->sym = r;
		return re;
	}
	static const RegExp *make_alt(const RegExp *r1, const RegExp *r2)
	{
		if (!r1) return r2;
		if (!r2) return r1;
		if (r1->type == RegExp::SYM && r2->type == RegExp::SYM) {
			return RegExp::make_sym(r1->line, r1->column,
				Range::add(r1->sym, r2->sym));
		}
		RegExp *re = new RegExp(r1->line, r1->column, ALT);
		re->alt.re1 = r1;
		re->alt.re2 = r2;
		return re;
	}
	static const RegExp *make_cat(const RegExp *r1, const RegExp *r2)
	{
		if (!r1) return r2;
		if (!r2) return r1;
		RegExp *re = new RegExp(r1->line, r1->column, CAT);
		re->cat.re1 = r1;
		re->cat.re2 = r2;
		return re;
	}
	static const RegExp *make_iter(const RegExp *r, uint32_t n, uint32_t m)
	{
		RegExp *re = new RegExp(r->line, r->column, ITER);
		re->iter.re = r;
		re->iter.min = n;
		re->iter.max = m;
		return re;
	}
	static const RegExp *make_tag(uint32_t l, uint32_t c, const std::string *t)
	{
		RegExp *re = new RegExp(l, c, TAG);
		re->tag = t;
		return re;
	}
	static const RegExp *make_cap(const RegExp *r)
	{
		RegExp *re = new RegExp(r->line, r->column, CAP);
		re->cap = r;
		return re;
	}
	static const RegExp *make_ref(const RegExp *r, const std::string &n)
	{
		RegExp *re = new RegExp(r->line, r->column, REF);
		re->ref.re = r;
		re->ref.name = new std::string(n);
		return re;
	}
	inline ~RegExp()
	{
		flist.erase(this);
		if (type == TAG) {
			delete tag;
		} else if (type == REF) {
			delete ref.name;
		}
	}
	static const RegExp *make_schar(uint32_t line, uint32_t column, uint32_t c, Opt &opts);
	static const RegExp *make_ichar(uint32_t line, uint32_t column, uint32_t c, Opt &opts);
	static const RegExp *make_class(uint32_t line, uint32_t column, const Range *r, Opt &opts, Warn &warn);
	static const RegExp *make_diff(const RegExp * e1, const RegExp * e2, Opt &opts, Warn &warn);
	static const RegExp *make_dot(uint32_t line, uint32_t column, Opt &opts, Warn &warn);
	static const RegExp *make_default(uint32_t line, uint32_t column, Opt &opts);
	static bool need_wrap(const RegExp *re);

private:
	inline RegExp(uint32_t l, uint32_t c, type_t t)
		: type(t), line(l), column(c)
	{
		flist.insert(this);
	}
};

struct RegExpRule
{
	const RegExp *re;
	const Code *code;

	RegExpRule(const RegExp *r, const Code *c)
		: re(r)
		, code(c)
	{}
};

} // end namespace re2c

#endif // _RE2C_IR_REGEXP_REGEXP_
