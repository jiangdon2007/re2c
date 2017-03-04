#include "src/util/c99_stdint.h"

#include "src/ir/regexp/encoding/utf8/utf8_regexp.h"
#include "src/ir/regexp/encoding/range_suffix.h"
#include "src/ir/regexp/encoding/utf8/utf8_range.h"
#include "src/ir/regexp/regexp.h"
#include "src/util/range.h"

namespace re2c {

const RegExp * UTF8Symbol(uint32_t l, uint32_t c, utf8::rune r)
{
	uint32_t chars[utf8::MAX_RUNE_LENGTH];
	const uint32_t chars_count = utf8::rune_to_bytes(chars, r);
	const RegExp *re = RegExp::make_sym(l, c, Range::sym(chars[0]));
	for (uint32_t i = 1; i < chars_count; ++i) {
		re = RegExp::make_cat(re, RegExp::make_sym(l, c, Range::sym(chars[i])));
	}
	return re;
}

/*
 * Split Unicode character class {[l1, h1), ..., [lN, hN)} into
 * ranges [l1, h1-1], ..., [lN, hN-1] and return alternation of
 * them. We store partially built range in suffix tree, which
 * allows to eliminate common suffixes while building.
 */
const RegExp * UTF8Range(uint32_t l, uint32_t c, const Range * r)
{
	RangeSuffix * root = NULL;
	for (; r != NULL; r = r->next ())
		UTF8splitByRuneLength(root, r->lower (), r->upper () - 1);
	return to_regexp (l, c, root);
}

} // namespace re2c
