#ifndef NONUT_CORE_STRING_HELPERS_H
#define NONUT_CORE_STRING_HELPERS_H
#include <string>
#include <map>

namespace nonut
{
	const std::map<unsigned char, std::string_view> windows1250_utf8_map
	{
		{'\x80', "\xe2\x82\xac"}, // euro sign
		{'\x82', "\xe2\x80\x9a"}, // lower quotation mark
		{'\x84', "\xe2\x80\x9e"}, // lower quotation marks
		{'\x85', "\xe2\x80\xa6"}, // ellipsis
		{'\x86', "\xe2\x80\xa0"}, // dagger
		{'\x87', "\xe2\x80\xa1"}, // double dagger
		{'\x89', "\xe2\x80\xb0"}, // per mille
		{'\x8a', "\xc5\xa0"}, // S with caron
		{'\x8b', "\xe2\x80\xb9"}, // left guillemet
		{'\x8c', "\xc5\x9a"}, // S with acute
		{'\x8d', "\xc5\xa4"}, // T with caron
		{'\x8e', "\xc5\xbd"}, // Z with caron
		{'\x8f', "\xc5\xb9"}, // Z with acute

		{'\x91', "\xe2\x80\x98"}, // upper quotation mark (opening)
		{'\x92', "\xe2\x80\x99"}, // upper quotation mark (closing)
		{'\x93', "\xe2\x80\x9c"}, // upper quotation marks (opening)
		{'\x94', "\xe2\x80\x9d"}, // upper quotation marks (closing)
		{'\x95', "\xe2\x80\xa2"}, // bullet sign
		{'\x96', "\xe2\x80\x93"}, // en dash
		{'\x97', "\xe2\x80\x94"}, // em dash
		{'\x99', "\xe2\x84\xa2"}, // trademark sign
		{'\x9a', "\xc5\xa1"}, // s with caron
		{'\x9b', "\xe2\x80\xba"}, // right guillemet
		{'\x9c', "\xc5\x9b"}, // s with acute
		{'\x9d', "\xc5\xa5"}, // t with caron
		{'\x9e', "\xc5\xbe"}, // z with caron
		{'\x9f', "\xc5\xba"}, // z with acute

		{'\xa0', "\x20"}, // NBSP
		{'\xa1', "\xcb\x87"}, // caron
		{'\xa2', "\xcb\x98"}, // breve
		{'\xa3', "\xc5\x81"}, // L with stroke
		{'\xa4', "\xc2\xa4"}, // currency sign
		{'\xa5', "\xc4\x84"}, // A with ogonek
		{'\xa6', "\xc2\xa6"}, // vertical bar
		{'\xa7', "\xc2\xa7"}, // section sign
		{'\xa8', "\xc2\xa8"}, // diaeresis
		{'\xa9', "\xc2\xa9"}, // copyright sign
		{'\xaa', "\xc5\x9e"}, // S-cedilla
		{'\xab', "\xc2\xab"}, // left guillemets
		{'\xac', "\xc2\xac"}, // negation
		{'\xad', "\xc2\xad"}, // soft hyphen
		{'\xae', "\xc2\xae"}, // registered trademark sign
		{'\xaf', "\xc5\xbb"}, // Z with dot above

		{'\xb0', "\xc2\xb0"}, // degree sign
		{'\xb1', "\xc2\xb1"}, // plus-minus sign
		{'\xb2', "\xcb\x9b"}, // ogonek
		{'\xb3', "\xc5\x82"}, // l with stroke
		{'\xb4', "\xc2\xb4"}, // acute accent
		{'\xb5', "\xc2\xb5"}, // Mu letter
		{'\xb6', "\xc2\xb6"}, // pilcrow
		{'\xb7', "\xc2\xb7"}, // middle dot
		{'\xb8', "\xc2\xb8"}, // cedilla
		{'\xb9', "\xc4\x85"}, // a with ogonek
		{'\xba', "\xc5\x9f"}, // s-cedilla
		{'\xbb', "\xc2\xbb"}, // right guillemets
		{'\xbc', "\xc4\xbd"}, // Lj-
		{'\xbd', "\xcb\x9d"}, // double acute accent
		{'\xbe', "\xc4\xbe"}, // lj-
		{'\xbf', "\xc5\xbc"}, // z with dot above

		{'\xc0', "\xc5\x94"}, // R with acute
		{'\xc1', "\xc3\x81"}, // A with acute
		{'\xc2', "\xc3\x82"}, // A-circumflex
		{'\xc3', "\xc4\x82"}, // A-breve
		{'\xc4', "\xc3\x84"}, // A with diaeresis
		{'\xc5', "\xc4\xb9"}, // L with acute
		{'\xc6', "\xc4\x86"}, // C with acute
		{'\xc7', "\xc3\x87"}, // C-cedilla
		{'\xc8', "\xc4\x8c"}, // C with caron
		{'\xc9', "\xc3\x89"}, // C with acute
		{'\xca', "\xc4\x98"}, // E with ogonek
		{'\xcb', "\xc3\x8b"}, // E with diaeresis
		{'\xcc', "\xc3\x8b"}, // E with caron
		{'\xcd', "\xc3\x8d"}, // I with acute
		{'\xce', "\xc3\x8e"}, // I-circumflex
		{'\xcf', "\xc4\x8e"}, // D with caron

		{'\xd0', "\xc4\x90"}, // crossed D
		{'\xd1', "\xc5\x83"}, // N with acute
		{'\xd2', "\xc5\x87"}, // N with caron
		{'\xd3', "\xc3\x93"}, // O with acute
		{'\xd4', "\xc3\x94"}, // O-circumflex
		{'\xd5', "\xc5\x90"}, // O with dobule accute
		{'\xd6', "\xc3\x96"}, // O with diaeresis
		{'\xd7', "\xc3\x97"}, // multiplication sign
		{'\xd8', "\xc5\x98"}, // R with caron
		{'\xd9', "\xc5\xae"}, // U with diacritic
		{'\xda', "\xc3\x9a"}, // U with acute
		{'\xdb', "\xc5\xb0"}, // U with double accent
		{'\xdc', "\xc3\x9c"}, // U with diaeresis
		{'\xdd', "\xc3\x9d"}, // Y with acute
		{'\xdf', "\xc5\xa2"}, // T-cedilla

		{'\xe0', "\xc5\x95"}, // r with acute
		{'\xe1', "\xc3\xa1"}, // a with acute
		{'\xe2', "\xc3\xa2"}, // a-circumflex
		{'\xe3', "\xc4\x83"}, // a-breve
		{'\xe4', "\xc3\xa4"}, // a with diaeresis
		{'\xe5', "\xc4\xba"}, // l with acute
		{'\xe6', "\xc4\x87"}, // c with acute
		{'\xe7', "\xc3\xa7"}, // c-cedilla
		{'\xe8', "\xc4\x8d"}, // c with caron
		{'\xe9', "\xc3\xa9"}, // c with acute
		{'\xea', "\xc4\x99"}, // e with ogonek
		{'\xeb', "\xc3\xab"}, // e with diaeresis
		{'\xec', "\xc4\x9b"}, // e with caron
		{'\xed', "\xc3\xad"}, // i with acute
		{'\xee', "\xc3\xae"}, // i-circumflex
		{'\xef', "\xc4\x8f"}, // d with caron

		{'\xf0', "\xc4\x91"}, // crossed d
		{'\xf1', "\xc5\x84"}, // n with acute
		{'\xf2', "\xc5\x88"}, // n with caron
		{'\xf3', "\xc3\xb3"}, // o with acute
		{'\xf4', "\xc3\xb4"}, // o-circumflex
		{'\xf5', "\xc5\x91"}, // o with double accent
		{'\xf6', "\xc3\xb6"}, // o with diaeresis
		{'\xf7', "\xc3\xb7"}, // division sign
		{'\xf8', "\xc5\x99"}, // r with caron
		{'\xf9', "\xc5\xaf"}, // u with diacritic
		{'\xfa', "\xc3\xba"}, // u with acute
		{'\xfb', "\xc5\xb1"}, // u with double accent
		{'\xfc', "\xc3\xbc"}, // u with diaeresis
		{'\xfd', "\xc3\xbd"}, // y with acute
		{'\xfe', "\xc5\xa3"}, // t-cedilla
		{'\xff', "\xcb\x99"}, // diactric dot
	};

	const std::map<std::string_view, unsigned char> utf8_windows1250_map
	{
		{"\xe2\x82\xac", '\x80'}, // euro sign
		{"\xe2\x80\x9a", '\x82'}, // lower quotation mark
		{"\xe2\x80\x9e", '\x84'}, // lower quotation marks
		{"\xe2\x80\xa6", '\x85'}, // ellipsis
		{"\xe2\x80\xa0", '\x86'}, // dagger
		{"\xe2\x80\xa1", '\x87'}, // double dagger
		{"\xe2\x80\xb0", '\x89'}, // per mille
		{"\xc5\xa0", '\x8a'}, // S with caron
		{"\xe2\x80\xb9", '\x8b'}, // left guillemet
		{"\xc5\x9a", '\x8c'}, // S with acute
		{"\xc5\xa4", '\x8d'}, // T with caron
		{"\xc5\xbd", '\x8e'}, // Z with caron
		{"\xc5\xb9", '\x8f'}, // Z with acute

		{"\xe2\x80\x98", '\x91'}, // upper quotation mark (opening)
		{"\xe2\x80\x99", '\x92'}, // upper quotation mark (closing)
		{"\xe2\x80\x9c", '\x93'}, // upper quotation marks (opening)
		{"\xe2\x80\x9d", '\x94'}, // upper quotation marks (closing)
		{"\xe2\x80\xa2", '\x95'}, // bullet sign
		{"\xe2\x80\x93", '\x96'}, // en dash
		{"\xe2\x80\x94", '\x97'}, // em dash
		{"\xe2\x84\xa2", '\x99'}, // trademark sign
		{"\xc5\xa1", '\x9a'}, // s with caron
		{"\xe2\x80\xba", '\x9b'}, // right guillemet
		{"\xc5\x9b", '\x9c'}, // s with acute
		{"\xc5\xa5", '\x9d'}, // t with caron
		{"\xc5\xbe", '\x9e'}, // z with caron
		{"\xc5\xba", '\x9f'}, // z with acute

		{"\x20", '\xa0'}, // NBSP
		{"\xcb\x87", '\xa1'}, // caron
		{"\xcb\x98", '\xa2'}, // breve
		{"\xc5\x81", '\xa3'}, // L with stroke
		{"\xc2\xa4", '\xa4'}, // currency sign
		{"\xc4\x84", '\xa5'}, // A with ogonek
		{"\xc2\xa6", '\xa6'}, // vertical bar
		{"\xc2\xa7", '\xa7'}, // section sign
		{"\xc2\xa8", '\xa8'}, // diaeresis
		{"\xc2\xa9", '\xa9'}, // copyright sign
		{"\xc5\x9e", '\xaa'}, // S-cedilla
		{"\xc2\xab", '\xab'}, // left guillemets
		{"\xc2\xac", '\xac'}, // negation
		{"\xc2\xad", '\xad'}, // soft hyphen
		{"\xc2\xae", '\xae'}, // registered trademark sign
		{"\xc5\xbb", '\xaf'}, // Z with dot above

		{"\xc2\xb0", '\xb0'}, // degree sign
		{"\xc2\xb1", '\xb1'}, // plus-minus sign
		{"\xcb\x9b", '\xb2'}, // ogonek
		{"\xc5\x82", '\xb3'}, // l with stroke
		{"\xc2\xb4", '\xb4'}, // acute accent
		{"\xc2\xb5", '\xb5'}, // Mu letter
		{"\xc2\xb6", '\xb6'}, // pilcrow
		{"\xc2\xb7", '\xb7'}, // middle dot
		{"\xc2\xb8", '\xb8'}, // cedilla
		{"\xc4\x85", '\xb9'}, // a with ogonek
		{"\xc5\x9f", '\xba'}, // s-cedilla
		{"\xc2\xbb", '\xbb'}, // right guillemets
		{"\xc4\xbd", '\xbc'}, // Lj-
		{"\xcb\x9d", '\xbd'}, // double acute accent
		{"\xc4\xbe", '\xbe'}, // lj-
		{"\xc5\xbc", '\xbf'}, // z with dot above

		{"\xc5\x94", '\xc0'}, // R with acute
		{"\xc3\x81", '\xc1'}, // A with acute
		{"\xc3\x82", '\xc2'}, // A-circumflex
		{"\xc4\x82", '\xc3'}, // A-breve
		{"\xc3\x84", '\xc4'}, // A with diaeresis
		{"\xc4\xb9", '\xc5'}, // L with acute
		{"\xc4\x86", '\xc6'}, // C with acute
		{"\xc3\x87", '\xc7'}, // C-cedilla
		{"\xc4\x8c", '\xc8'}, // C with caron
		{"\xc3\x89", '\xc9'}, // C with acute
		{"\xc4\x98", '\xca'}, // E with ogonek
		{"\xc3\x8b", '\xcb'}, // E with diaeresis
		{"\xc3\x8b", '\xcc'}, // E with caron
		{"\xc3\x8d", '\xcd'}, // I with acute
		{"\xc3\x8e", '\xce'}, // I-circumflex
		{"\xc4\x8e", '\xcf'}, // D with caron

		{"\xc4\x90", '\xd0'}, // crossed D
		{"\xc5\x83", '\xd1'}, // N with acute
		{"\xc5\x87", '\xd2'}, // N with caron
		{"\xc3\x93", '\xd3'}, // O with acute
		{"\xc3\x94", '\xd4'}, // O-circumflex
		{"\xc5\x90", '\xd5'}, // O with dobule accute
		{"\xc3\x96", '\xd6'}, // O with diaeresis
		{"\xc3\x97", '\xd7'}, // multiplication sign
		{"\xc5\x98", '\xd8'}, // R with caron
		{"\xc5\xae", '\xd9'}, // U with diacritic
		{"\xc3\x9a", '\xda'}, // U with acute
		{"\xc5\xb0", '\xdb'}, // U with double accent
		{"\xc3\x9c", '\xdc'}, // U with diaeresis
		{"\xc3\x9d", '\xdd'}, // Y with acute
		{"\xc5\xa2", '\xdf'}, // T-cedilla

		{"\xc5\x95", '\xe0'}, // r with acute
		{"\xc3\xa1", '\xe1'}, // a with acute
		{"\xc3\xa2", '\xe2'}, // a-circumflex
		{"\xc4\x83", '\xe3'}, // a-breve
		{"\xc3\xa4", '\xe4'}, // a with diaeresis
		{"\xc4\xba", '\xe5'}, // l with acute
		{"\xc4\x87", '\xe6'}, // c with acute
		{"\xc3\xa7", '\xe7'}, // c-cedilla
		{"\xc4\x8d", '\xe8'}, // c with caron
		{"\xc3\xa9", '\xe9'}, // c with acute
		{"\xc4\x99", '\xea'}, // e with ogonek
		{"\xc3\xab", '\xeb'}, // e with diaeresis
		{"\xc4\x9b", '\xec'}, // e with caron
		{"\xc3\xad", '\xed'}, // i with acute
		{"\xc3\xae", '\xee'}, // i-circumflex
		{"\xc4\x8f", '\xef'}, // d with caron

		{"\xc4\x91", '\xf0'}, // crossed d
		{"\xc5\x84", '\xf1'}, // n with acute
		{"\xc5\x88", '\xf2'}, // n with caron
		{"\xc3\xb3", '\xf3'}, // o with acute
		{"\xc3\xb4", '\xf4'}, // o-circumflex
		{"\xc5\x91", '\xf5'}, // o with double accent
		{"\xc3\xb6", '\xf6'}, // o with diaeresis
		{"\xc3\xb7", '\xf7'}, // division sign
		{"\xc5\x99", '\xf8'}, // r with caron
		{"\xc5\xaf", '\xf9'}, // u with diacritic
		{"\xc3\xba", '\xfa'}, // u with acute
		{"\xc5\xb1", '\xfb'}, // u with double accent
		{"\xc3\xbc", '\xfc'}, // u with diaeresis
		{"\xc3\xbd", '\xfd'}, // y with acute
		{"\xc5\xa3", '\xfe'}, // t-cedilla
		{"\xcb\x99", '\xff'}, // diactric dot
	};

	inline std::string win1250ToUTF8(const std::string& strRef)
	{
		std::string result;
		result.reserve(strRef.size() * 2);

		for (auto&& c : strRef)
		{
			if (windows1250_utf8_map.contains(static_cast<unsigned char>(c)))
				result += windows1250_utf8_map.at(static_cast<unsigned char>(c));
			else
				result += c;
		}

		return result;
	}

	inline std::string UTF8ToWin1250(const std::string& strRef)
	{
		std::string result;
		result.reserve(strRef.size());
		size_t charSize = 1;

		for (size_t i = 0; i < strRef.length(); ++i)
		{
			if (const int c = static_cast<unsigned char>(strRef[i]); c >= 128)
			{
				if (c < 224)
					charSize = 2;
				else if (c < 240)
					charSize = 3;
				else if (c < 248)
					charSize = 4;
				else if (c == 252)
					charSize = 5;
				else
					charSize = 6;
			}
			// Update loop index according to UTF8 charSize;
			i += charSize - 1;

			if (charSize == 1)
			{
				result += strRef[i];
				continue;
			}

			if (i + charSize > strRef.length())
			{
				result += '?';
				return result;
			}

			String utfChar;
			utfChar.reserve(charSize);

			for (size_t j = 0; j < charSize; ++j)
			{
				utfChar += strRef[i + j];
			}

			if (utf8_windows1250_map.contains(utfChar))
			{
				result += static_cast<char>(utf8_windows1250_map.at(utfChar));
			}
			else
			{
				result += '?';
			}
		}

		return result;
	}
}
#endif // NONUT_CORE_STRING_HELPERS_H
