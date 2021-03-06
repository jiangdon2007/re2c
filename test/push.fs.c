/* Generated by re2c */
#line 1 "push.fs.re"
uint32_t push()
{
    // The scanner starts here
    #define YYLIMIT         limit
    #define YYCURSOR        cursor
    #define YYMARKER        marker
    #define YYCTYPE         uint8_t

    #define SKIP(x)         { start = cursor; goto yy0; }
    #define SEND(x)         { send(x); SKIP();          }
    #define YYFILL(n)       { goto fill;                }

    #define YYGETSTATE()    state
    #define YYSETSTATE(x)   { state = (x);  }

start:

    
#line 22 "push.fs.c"

	switch (YYGETSTATE()) {
	default:
		goto yy0;
	case 0:
		goto yyFillLabel0;
	case 1:
		goto yyFillLabel1;
	case 2:
		goto yyFillLabel2;
	}
yy0:
	YYSETSTATE(0);
	if ((YYLIMIT - YYCURSOR) < 7) YYFILL(7);
yyFillLabel0:
	yych = *YYCURSOR;
	if (yych <= '=') {
		if (yych <= '(') {
			if (yych <= '\n') {
				if (yych <= 0x00) goto yy3;
				if (yych <= 0x08) goto yy5;
				if (yych <= '\t') goto yy7;
				goto yy9;
			} else {
				if (yych <= 0x1F) {
					if (yych <= '\r') goto yy7;
					goto yy5;
				} else {
					if (yych <= ' ') goto yy7;
					if (yych <= '\'') goto yy5;
					goto yy11;
				}
			}
		} else {
			if (yych <= '-') {
				if (yych <= '*') {
					if (yych <= ')') goto yy13;
					goto yy15;
				} else {
					if (yych <= '+') goto yy17;
					if (yych <= ',') goto yy5;
					goto yy19;
				}
			} else {
				if (yych <= '/') {
					if (yych <= '.') goto yy5;
					goto yy21;
				} else {
					if (yych <= '9') goto yy23;
					if (yych <= '<') goto yy5;
					goto yy26;
				}
			}
		}
	} else {
		if (yych <= 'e') {
			if (yych <= '_') {
				if (yych <= '@') goto yy5;
				if (yych <= 'Z') goto yy28;
				if (yych <= '^') goto yy5;
				goto yy28;
			} else {
				if (yych <= 'a') {
					if (yych <= '`') goto yy5;
					goto yy28;
				} else {
					if (yych <= 'b') goto yy31;
					if (yych <= 'd') goto yy28;
					goto yy32;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= 'g') {
					if (yych <= 'f') goto yy33;
					goto yy34;
				} else {
					if (yych == 'i') goto yy35;
					goto yy28;
				}
			} else {
				if (yych <= 'v') {
					if (yych <= 'r') goto yy36;
					goto yy28;
				} else {
					if (yych <= 'w') goto yy37;
					if (yych <= 'z') goto yy28;
					goto yy5;
				}
			}
		}
	}
yy3:
	++YYCURSOR;
#line 48 "push.fs.re"
	{ send(kEOF); return 1;  }
#line 119 "push.fs.c"
yy5:
	++YYCURSOR;
#line 49 "push.fs.re"
	{ SEND(kUnknown);        }
#line 124 "push.fs.c"
yy7:
	++YYCURSOR;
#line 47 "push.fs.re"
	{ SKIP();                }
#line 129 "push.fs.c"
yy9:
	++YYCURSOR;
#line 46 "push.fs.re"
	{ SKIP();                }
#line 134 "push.fs.c"
yy11:
	++YYCURSOR;
#line 39 "push.fs.re"
	{ SEND(kLeftParen);      }
#line 139 "push.fs.c"
yy13:
	++YYCURSOR;
#line 40 "push.fs.re"
	{ SEND(kRightParen);     }
#line 144 "push.fs.c"
yy15:
	++YYCURSOR;
#line 43 "push.fs.re"
	{ SEND(kStar);           }
#line 149 "push.fs.c"
yy17:
	++YYCURSOR;
#line 42 "push.fs.re"
	{ SEND(kPlus);           }
#line 154 "push.fs.c"
yy19:
	++YYCURSOR;
#line 41 "push.fs.re"
	{ SEND(kMinus);          }
#line 159 "push.fs.c"
yy21:
	++YYCURSOR;
#line 44 "push.fs.re"
	{ SEND(kSlash);          }
#line 164 "push.fs.c"
yy23:
	++YYCURSOR;
	YYSETSTATE(1);
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
yyFillLabel1:
	yych = *YYCURSOR;
	if (yych <= '/') goto yy25;
	if (yych <= '9') goto yy23;
yy25:
#line 36 "push.fs.re"
	{ SEND(kDecimalConstant);}
#line 176 "push.fs.c"
yy26:
	++YYCURSOR;
#line 38 "push.fs.re"
	{ SEND(kEqual);          }
#line 181 "push.fs.c"
yy28:
	++YYCURSOR;
	YYSETSTATE(2);
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
yyFillLabel2:
	yych = *YYCURSOR;
yy29:
	if (yych <= 'Z') {
		if (yych <= '/') goto yy30;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy30;
			if (yych <= 'z') goto yy28;
		}
	}
yy30:
#line 35 "push.fs.re"
	{ SEND(kIdentifier);     }
#line 204 "push.fs.c"
yy31:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy38;
	goto yy29;
yy32:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy39;
	goto yy29;
yy33:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy40;
	goto yy29;
yy34:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy41;
	goto yy29;
yy35:
	yych = *++YYCURSOR;
	if (yych == 'f') goto yy42;
	goto yy29;
yy36:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy44;
	goto yy29;
yy37:
	yych = *++YYCURSOR;
	if (yych == 'h') goto yy45;
	goto yy29;
yy38:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy46;
	goto yy29;
yy39:
	yych = *++YYCURSOR;
	if (yych == 's') goto yy47;
	goto yy29;
yy40:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy48;
	goto yy29;
yy41:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy50;
	goto yy29;
yy42:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy43;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy43;
			if (yych <= 'z') goto yy28;
		}
	}
yy43:
#line 28 "push.fs.re"
	{ SEND(kIf);             }
#line 266 "push.fs.c"
yy44:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy51;
	goto yy29;
yy45:
	yych = *++YYCURSOR;
	if (yych == 'i') goto yy52;
	goto yy29;
yy46:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy53;
	goto yy29;
yy47:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy54;
	goto yy29;
yy48:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy49;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy49;
			if (yych <= 'z') goto yy28;
		}
	}
yy49:
#line 29 "push.fs.re"
	{ SEND(kFor);            }
#line 300 "push.fs.c"
yy50:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy56;
	goto yy29;
yy51:
	yych = *++YYCURSOR;
	if (yych == 'u') goto yy58;
	goto yy29;
yy52:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy59;
	goto yy29;
yy53:
	yych = *++YYCURSOR;
	if (yych == 'k') goto yy60;
	goto yy29;
yy54:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy55;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy55;
			if (yych <= 'z') goto yy28;
		}
	}
yy55:
#line 30 "push.fs.re"
	{ SEND(kElse);           }
#line 334 "push.fs.c"
yy56:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy57;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy57;
			if (yych <= 'z') goto yy28;
		}
	}
yy57:
#line 31 "push.fs.re"
	{ SEND(kGoto);           }
#line 352 "push.fs.c"
yy58:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy62;
	goto yy29;
yy59:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy63;
	goto yy29;
yy60:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy61;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy61;
			if (yych <= 'z') goto yy28;
		}
	}
yy61:
#line 32 "push.fs.re"
	{ SEND(kBreak);          }
#line 378 "push.fs.c"
yy62:
	yych = *++YYCURSOR;
	if (yych == 'n') goto yy65;
	goto yy29;
yy63:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy64;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy64;
			if (yych <= 'z') goto yy28;
		}
	}
yy64:
#line 33 "push.fs.re"
	{ SEND(kWhile);          }
#line 400 "push.fs.c"
yy65:
	yych = *++YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy66;
		if (yych <= '9') goto yy28;
		if (yych >= 'A') goto yy28;
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy28;
		} else {
			if (yych <= '`') goto yy66;
			if (yych <= 'z') goto yy28;
		}
	}
yy66:
#line 34 "push.fs.re"
	{ SEND(kReturn);         }
#line 418 "push.fs.c"
#line 50 "push.fs.re"


fill:
    return 0;
}
push.fs.re:26:18: warning: escape has no effect: '\h' [-Wuseless-escape]
