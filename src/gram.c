#define	SEOS	1
#define	SCOMMENT	2
#define	SLABEL	3
#define	SUNKNOWN	4
#define	SHOLLERITH	5
#define	SICON	6
#define	SRCON	7
#define	SDCON	8
#define	SBITCON	9
#define	SOCTCON	10
#define	SHEXCON	11
#define	STRUE	12
#define	SFALSE	13
#define	SNAME	14
#define	SNAMEEQ	15
#define	SFIELD	16
#define	SSCALE	17
#define	SINCLUDE	18
#define	SLET	19
#define	SASSIGN	20
#define	SAUTOMATIC	21
#define	SBACKSPACE	22
#define	SBLOCK	23
#define	SCALL	24
#define	SCHARACTER	25
#define	SCLOSE	26
#define	SCOMMON	27
#define	SCOMPLEX	28
#define	SCONTINUE	29
#define	SDATA	30
#define	SDCOMPLEX	31
#define	SDIMENSION	32
#define	SDO	33
#define	SDOUBLE	34
#define	SELSE	35
#define	SELSEIF	36
#define	SEND	37
#define	SENDFILE	38
#define	SENDIF	39
#define	SENTRY	40
#define	SEQUIV	41
#define	SEXTERNAL	42
#define	SFORMAT	43
#define	SFUNCTION	44
#define	SGOTO	45
#define	SASGOTO	46
#define	SCOMPGOTO	47
#define	SARITHIF	48
#define	SLOGIF	49
#define	SIMPLICIT	50
#define	SINQUIRE	51
#define	SINTEGER	52
#define	SINTRINSIC	53
#define	SLOGICAL	54
#define	SNAMELIST	55
#define	SOPEN	56
#define	SPARAM	57
#define	SPAUSE	58
#define	SPRINT	59
#define	SPROGRAM	60
#define	SPUNCH	61
#define	SREAD	62
#define	SREAL	63
#define	SRETURN	64
#define	SREWIND	65
#define	SSAVE	66
#define	SSTATIC	67
#define	SSTOP	68
#define	SSUBROUTINE	69
#define	STHEN	70
#define	STO	71
#define	SUNDEFINED	72
#define	SWRITE	73
#define	SLPAR	74
#define	SRPAR	75
#define	SEQUALS	76
#define	SCOLON	77
#define	SCOMMA	78
#define	SCURRENCY	79
#define	SPLUS	80
#define	SMINUS	81
#define	SSTAR	82
#define	SSLASH	83
#define	SPOWER	84
#define	SCONCAT	85
#define	SAND	86
#define	SOR	87
#define	SNEQV	88
#define	SEQV	89
#define	SNOT	90
#define	SEQ	91
#define	SLT	92
#define	SGT	93
#define	SLE	94
#define	SGE	95
#define	SNE	96
#define	SENDDO	97
#define	SWHILE	98
#define	SSLASHD	99
#define	SBYTE	100

/* #line	125	"gram.in" */
#include "defs.h"
#include "p1defs.h"

static int nstars;			/* Number of labels in an
					   alternate return CALL */
static int datagripe;
static int ndim;
static int vartype;
int new_dcl;
static ftnint varleng;
static struct Dims dims[MAXDIM+1];
extern struct Labelblock **labarray;	/* Labels in an alternate
						   return CALL */
extern int maxlablist;

/* The next two variables are used to verify that each statement might be reached
   during runtime.   lastwasbranch   is tested only in the defintion of the
   stat:   nonterminal. */

int lastwasbranch = NO;
static int thiswasbranch = NO;
extern ftnint yystno;
extern flag intonly;
static chainp datastack;
extern long laststfcn, thisstno;
extern int can_include;	/* for netlib */
extern struct Primblock *primchk Argdcl((expptr));

#define ESNULL (Extsym *)0
#define NPNULL (Namep)0
#define LBNULL (struct Listblock *)0

 static void
pop_datastack(Void) {
	chainp d0 = datastack;
	if (d0->datap)
		curdtp = (chainp)d0->datap;
	datastack = d0->nextp;
	d0->nextp = 0;
	frchain(&d0);
	}


/* #line	171	"gram.in" */
typedef union 	{
	int ival;
	ftnint lval;
	char *charpval;
	chainp chval;
	tagptr tagval;
	expptr expval;
	struct Labelblock *labval;
	struct Nameblock *namval;
	struct Eqvchain *eqvval;
	Extsym *extval;
	} YYSTYPE;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define YYEOFCODE 1
#define YYERRCODE 2
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
-1, 20,
	4, 38,
	-2, 229,
-1, 24,
	4, 42,
	-2, 229,
-1, 151,
	4, 245,
	-2, 189,
-1, 175,
	4, 266,
	81, 266,
	-2, 189,
-1, 225,
	80, 174,
	-2, 140,
-1, 246,
	77, 229,
	-2, 226,
-1, 272,
	4, 287,
	-2, 144,
-1, 276,
	4, 296,
	81, 296,
	-2, 146,
-1, 329,
	80, 175,
	-2, 142,
-1, 359,
	4, 268,
	17, 268,
	77, 268,
	81, 268,
	-2, 190,
-1, 437,
	94, 0,
	95, 0,
	96, 0,
	97, 0,
	98, 0,
	99, 0,
	-2, 154,
-1, 454,
	4, 290,
	81, 290,
	-2, 144,
-1, 456,
	4, 292,
	81, 292,
	-2, 144,
-1, 458,
	4, 294,
	81, 294,
	-2, 144,
-1, 460,
	4, 297,
	81, 297,
	-2, 145,
-1, 504,
	81, 290,
	-2, 144,
};
#define	YYNPROD	302
#define	YYPRIVATE 57344
#define	YYLAST	1391
short	yyact[] =
{
 239, 275, 472, 413, 387, 425, 400, 414, 305, 267,
 100, 471, 293, 358, 398, 298, 399, 236, 357, 327,
 296, 224, 318, 253, 314, 231, 304, 274, 157, 317,
 117, 107, 265,  17, 129, 112, 271, 204, 184, 202,
 119, 185, 200, 122, 203, 337, 397, 104, 238, 196,
 397, 534, 312, 166, 167, 335, 336, 337, 343, 342,
 102, 261, 310, 191, 344, 346, 345, 348, 347, 349,
 121, 396, 120, 279, 335, 336, 337, 158, 104, 158,
 105, 115, 131, 132, 133, 134, 520, 136, 259, 260,
 261, 166, 167, 335, 336, 337, 343, 342, 341, 340,
 339, 106, 344, 346, 345, 348, 347, 349, 104, 130,
  73, 476, 484,  95,  70, 538, 524,  66, 104, 410,
  68,  72, 273,  67, 409, 156, 521, 156,  96,  97,
  98, 319, 213, 526, 212, 186, 447, 211, 104, 187,
 188,  64, 428,  69, 232, 242, 242, 121, 195, 120,
 482, 194,  65, 483, 469, 158,  74, 470, 258, 158,
 245,  71, 101, 241, 243, 166, 167, 259, 260, 261,
 262, 485, 217, 158, 222, 221, 295, 220, 481, 291,
 463, 216, 234, 249, 158,  99, 295, 263, 466,  75,
 166, 167, 335, 336, 337, 276, 276, 464, 269, 462,
 465, 264, 266, 156, 101, 448, 300, 156, 447, 461,
 372, 418, 283, 189, 419, 278, 321, 322, 301, 101,
 407, 156, 316, 408, 453, 325, 391, 329, 444, 392,
 331, 289, 156, 334, 290, 360, 429, 351, 361, 311,
 309, 353, 354, 334, 378, 332, 355, 350, 333, 150,
 258, 287, 288, 158, 280, 281, 282, 356, 363, 158,
 158, 158, 158, 158, 258, 258, 423, 324, 166, 167,
 335, 336, 337, 343, 377, 376, 334, 270, 208, 379,
 178, 362, 113, 111, 258, 110, 109, 366, 367, 368,
 369, 370, 108, 420, 225, 276, 423, 251, 223, 373,
 401, 156, 374, 375, 388, 382, 535, 156, 156, 156,
 156, 156, 166, 167, 259, 260, 261, 402, 531, 530,
 529, 525, 334, 334, 528, 351, 334, 171, 173, 177,
 334, 393, 334, 523, 411, 232, 433, 434, 435, 436,
 437, 438, 439, 440, 441, 442, 421, 104, 404, 104,
 406, 492, 334, 389, 334, 334, 334, 383, 384, 432,
 272, 272, 158, 258, 334, 385, 427, 258, 258, 258,
 258, 258, 494, 297, 151, 446, 175, 422, 192, 308,
 334, 286, 452, 247, 244, 449, 228, 225, 201, 214,
 450, 210, 172, 142, 276, 276, 276, 473, 401, 330,
 381, 491, 104, 415, 509, 468, 388, 307, 477, 269,
 156, 467, 475, 209, 213, 402, 227,  93, 352, 480,
  30,   6, 487,   4, 488, 490, 250,   5,  82,  81,
 242, 496, 237,  80, 334, 334, 334, 334, 334, 334,
 334, 334, 334, 334, 486, 497, 404, 138, 495, 493,
 404, 258,  79, 174, 124,  78,  77,  76,  60, 501,
 380, 500,  49, 452,  48, 499, 103,  45,  33, 114,
 508, 206, 473, 412, 334, 118, 502, 401, 137, 276,
 276, 276, 511, 514, 505, 506, 507, 517, 334, 334,
 480, 334, 518, 513, 402, 515, 242, 334, 522, 455,
 457, 459, 510, 527, 516, 205, 352, 395, 394, 155,
 299, 155, 451, 479, 533, 532, 135, 166, 167, 259,
 260, 261, 262, 536, 215, 404, 390, 313, 334, 116,
  26,  25,  24,  23, 334,  22,  21, 334, 537, 386,
 285,   9,   8, 103, 103, 103, 103,   7, 190,   2,
 302,  20, 539, 193, 165,  51, 197, 198, 199, 454,
 456, 458, 489, 207, 292, 230, 161, 162, 163, 164,
 170, 169, 168, 159, 160, 104, 328, 326, 416, 197,
 218, 219,  92, 256, 455, 457, 459, 155, 352,  53,
 338, 155,  19, 371,  55, 246,  37, 248, 166, 167,
 259, 260, 261, 262, 226, 155, 268,   3,   1,   0,
   0,   0,   0,   0, 512,   0, 155, 166, 167, 335,
 336, 337, 343, 342, 341, 340, 339, 498, 344, 346,
 345, 348, 347, 349, 303, 235, 306, 103,   0,   0,
 294, 166, 167, 474, 504, 456, 458,   0,   0,   0,
   0, 240,   0,   0,   0,   0, 118,   0, 315,   0,
 320, 460,   0,   0,   0, 197, 166, 167, 335, 336,
 337, 343, 342, 341, 340, 339,   0, 344, 346, 345,
 348, 347, 349,   0,   0, 155,   0,   0,   0,   0,
   0, 155, 155, 155, 155, 155,   0,   0,   0, 268,
 445,   0, 268, 268,   0, 166, 167, 335, 336, 337,
 343, 342, 341, 340, 339,   0, 344, 346, 345, 348,
 347, 349,   0,   0,   0, 443,   0,   0,   0,   0,
 166, 167, 335, 336, 337, 343, 342, 341, 340, 339,
 306, 344, 346, 345, 348, 347, 349, 403, 197,   0,
   0,   0,   0,   0,   0,   0,   0,   0, 417,   0,
   0,   0,   0, 431, 320,   0,   0,   0, 166, 167,
 335, 336, 337, 343, 342, 341, 340, 339, 430, 344,
 346, 345, 348, 347, 349,   0,   0,   0,   0,   0,
 424,   0,   0,   0, 155, 166, 167, 335, 336, 337,
 343, 342, 341, 340, 339, 268, 344, 346, 345, 348,
 347, 349, 166, 167, 335, 336, 337, 343, 342, 341,
 340, 339,   0, 344, 346, 345, 348, 347, 349,   0,
 161, 162, 163, 164, 170, 169, 168, 159, 160, 104,
 294, 478,   0, 306,   0, 403,   0,   0,   0, 403,
 166, 167, 335, 336, 337, 343, 342, 341,   0,   0,
   0, 344, 346, 345, 348, 347, 349, 315, 166, 167,
 335, 336, 337, 343,   0,   0,   0,   0,   0, 344,
 346, 345, 348, 347, 349, 359, 268,   0,   0,   0,
 166, 167, 259, 260, 261, 262,   0,   0,   0, 235,
 229, 503,   0,   0,   0, 166, 167, 233,   0, 503,
 503, 503,   0,   0, 306, 240,   0,   0,   0,   0,
  12,   0,   0,   0, 403,   0,   0,   0,   0, 503,
   0,   0,   0, 519,  10,  56,  46,  73,  86,  14,
  61,  70,  91,  38,  66,  47,  42,  68,  72,  31,
  67,  35,  34,  11,  88,  36,  18,  41,  39,  28,
  16,  57,  58,  59,  50,  54,  43,  89,  64,  40,
  69,  44,  90,  29,  62,  85,  13,   0,  83,  65,
  52,  87,  27,  74,  63,  15,   0,   0,  71,  84,
 161, 162, 163, 164, 170, 169, 168, 159, 160, 104,
   0, 161, 162, 163, 164, 170, 169, 168, 159, 160,
 104,   0,   0,  32,   0,   0,  75,   0, 161, 162,
 163, 164, 170, 169, 168, 159, 160, 104,   0, 161,
 162, 163, 164, 170, 169, 168, 159, 160, 104,   0,
 161, 162, 163, 164, 170, 169, 168, 159, 160, 104,
   0,   0,   0,   0,   0,   0,   0,   0,   0, 235,
   0,   0,   0,   0,   0, 166, 167, 364,   0, 365,
 235,   0,   0,   0,   0, 240, 166, 167, 233,   0,
   0,   0,   0,   0,   0,   0, 240, 235,   0,   0,
   0,   0,   0, 166, 167, 426,   0,   0, 235,   0,
   0,   0,   0, 240, 166, 167,  94,   0,   0, 277,
   0,   0,   0,   0, 240, 166, 167,   0,   0,   0,
   0,   0,   0,   0,   0, 240, 161, 162, 163, 164,
 170, 169, 168, 159, 160, 104,   0,   0, 123,   0,
   0, 126, 127, 128,   0,   0,   0,   0,   0,   0,
   0,   0,   0, 139, 140,   0,   0, 141,   0, 143,
 144, 145,   0,   0, 146, 147, 148,   0, 149, 161,
 162, 163, 164, 170, 169, 168, 159, 160, 104, 257,
   0,   0,   0,   0,   0,   0,   0,   0, 179, 180,
 181, 182, 183,   0,   0, 323,   0,   0,   0,   0,
   0, 166, 167,   0,   0,   0,   0,   0,   0,   0,
   0, 240, 161, 162, 163, 164, 170, 169, 168, 159,
 160, 104,   0, 161, 162, 163, 164, 170, 169, 168,
 159, 160, 104,   0,   0,   0,   0,   0, 252,   0,
   0,   0,   0,   0, 166, 167, 254,   0, 255, 161,
 162, 163, 164, 170, 169, 168, 159, 160, 104, 161,
 162, 163, 164, 170, 169, 168, 159, 160, 104, 161,
 162, 163, 164, 170, 169, 168, 159, 160, 104,   0,
   0, 154,   0,   0,   0,   0,   0, 166, 167, 152,
   0, 153, 252,   0,   0,   0,   0,   0, 166, 167,
 284, 161, 162, 163, 164, 170, 169, 168, 159, 160,
 104,   0,   0,   0,   0,   0,   0,   0, 154,   0,
   0,   0,   0,   0, 166, 167, 176,   0, 405,   0,
   0,   0,   0,   0, 166, 167,  56,  46, 252,  86,
   0,  61,   0,  91, 166, 167,  47,   0,   0,   0,
   0,   0,   0,   0,   0,  88,   0,   0,   0,   0,
   0,   0,  57,  58,  59,  50,   0,   0,  89,   0,
   0,   0,   0,  90,   0,  62,  85,   0,   0,  83,
   0,  52,  87,   0,   0,  63,   0, 125,   0,   0,
  84
};
short	yypact[] =
{
-1000, 421, 417, 913,-1000,-1000,-1000,-1000,-1000,-1000,
 409,-1000,-1000,-1000,-1000,-1000,-1000, 138, 385,  -1,
 211, 205, 204, 202,  81, 201,  -5,  61,-1000,-1000,
-1000,-1000,-1000,1314,-1000,-1000,-1000,  24,-1000,-1000,
-1000,-1000,-1000,-1000,-1000, 385,-1000,-1000,-1000,-1000,
-1000, 316,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,1204, 315,1241, 315,
 199,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000, 385, 385, 385, 385,-1000,
 385,-1000, 301,-1000,-1000, 385,-1000, -16, 385, 385,
 385, 311,-1000,-1000,-1000, 385, 197,-1000,-1000,-1000,
-1000, 396, 314, 123,-1000,-1000, 312,-1000,-1000,-1000,
-1000,  61, 385, 385, 311,-1000,-1000, 219, 310, 407,
-1000, 309, 822,1021,1021, 307, 405, 385, 306, 385,
-1000,-1000,-1000,-1000,1161,-1000,-1000,  82,1261,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,1161, 121, 196,-1000,-1000,1032,1032,-1000,
-1000,-1000,-1000,1215, 304,-1000,-1000, 301, 301, 385,
-1000,-1000, 101, 296,-1000,  81,-1000, 296,-1000,-1000,
-1000, 385,-1000, 330,-1000, 302,  86, -24,  61, -34,
 385,  81,  30,-1000,1021,1118,-1000, 385,-1000,-1000,
-1000,-1000,-1000,1021,-1000,1021, 325,-1000,1021,-1000,
 167,-1000, 729, 405,-1000,1021,-1000,-1000,-1000,1021,
1021,-1000, 729,-1000,1021,-1000,  81, 405,-1000, 807,
 157,-1000,1261,-1000,-1000,-1000, 982,-1000,1261,1261,
1261,1261,1261, -26, 515, 129, 332,-1000,-1000, 332,
 332,-1000, 194, 193, 163, 729,-1000,1032,-1000,-1000,
-1000,-1000,-1000,  82,-1000,-1000, 287,-1000,-1000, 301,
-1000,-1000, 148,-1000,-1000,-1000,  24,-1000, -31,1251,
 385,-1000, 142,-1000,  38,-1000,-1000, 330, 386,-1000,
 385,-1000,-1000, 133,-1000, 214,  30,-1000,-1000, 300,
 187, 712, 729,1010,-1000, 729, 288,  62, 155, 729,
 385, 685,-1000, 993,1021,1021,1021,1021,1021,1021,
1021,1021,1021,1021,-1000,-1000,-1000,-1000,-1000,-1000,
-1000, 647, 147, -42, 785, 622, 298, 127,-1000,-1000,
-1000,1161, 434, 729,-1000,-1000,   3, -26, -26, -26,
 229,-1000, 332, 129, 143, 129,1032,1032,1032, 583,
 128, 118,  99,-1000,-1000,-1000, 119,-1000, 109,-1000,
 296,-1000,  91,-1000,  76, 558,-1000,1251,-1000,-1000,
  26,1293,-1000,-1000,-1000,1021,-1000,-1000, 385,-1000,
 330,  97,  72,-1000,  28,-1000,  90,-1000,-1000, 385,
1021,-1000,1021,1021, 328,-1000, 273, 295,1021,1021,
-1000, 405,-1000, -11, -42, -42, -42, 185, 767, 767,
 -30, 785, 107,-1000,1021,-1000, 405, 405,  81,-1000,
  82,-1000,-1000, 332,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,1032,1032,1032,-1000, 389, 387,  24,-1000,-1000,
 558,-1000,-1000, 534,-1000,-1000,1251,-1000,-1000,-1000,
-1000, 330,-1000, 386, 386, 385,-1000, 729,   8,  45,
 729,-1000,-1000,-1000,1021, 255, 729,  35, 243,  55,
-1000,1021, 246, 217, 243, 242, 241, 240,-1000,-1000,
-1000,-1000, 558,-1000,-1000, -35, 228,-1000,-1000,-1000,
-1000,1021,-1000,-1000, 405,-1000,-1000, 729,-1000,-1000,
-1000,-1000,-1000, 729,-1000,-1000, 729,  34, 405,-1000
};
short	yypgo[] =
{
   0, 608, 607,  13, 604, 122,   9,  33, 596, 594,
 592,   7,   0, 590, 589, 583,  34, 582,   8,  26,
 578, 577, 576,  22,  29, 565,  63, 564, 562,  32,
  36,  27,  21, 447,  12, 555,  49, 432,   1, 182,
  19,  28, 297,   2,   6,  16,  25,  17,  48, 554,
 551,  40,  41,  38, 550, 549, 547, 542, 541,1106,
 113, 540, 539,   4, 536, 535, 533, 532, 531, 530,
 529,  43, 527,  10, 526,  20,  44,  15, 524,   5,
  42, 516,  39, 513, 510,  14,  30,  24, 508, 507,
  11,  18,  37, 505, 473, 471,   3, 469, 420, 468,
 467, 464, 462, 458, 457, 249, 456, 455, 453, 452,
 433, 429,  73, 428, 426,  23
};
short	yyr1[] =
{
   0,   1,   1,  55,  55,  55,  55,  55,  55,  55,
   2,  56,  56,  56,  56,  56,  56,  56,  60,  52,
  33,  53,  53,  61,  61,  62,  62,  63,  63,  26,
  26,  26,  27,  27,  34,  34,  17,  57,  57,  57,
  57,  57,  57,  57,  57,  57,  57,  57,  57,  10,
  10,  10,  74,   7,   8,   9,   9,   9,   9,   9,
   9,   9,   9,   9,   9,   9,   9,  16,  16,  16,
  50,  50,  50,  50,  51,  51,  64,  64,  65,  65,
  66,  66,  80,  54,  54,  67,  67,  81,  82,  76,
  83,  84,  77,  77,  85,  85,  45,  45,  45,  70,
  70,  86,  86,  72,  72,  87,  36,  18,  18,  19,
  19,  75,  75,  89,  88,  88,  90,  90,  43,  43,
  91,  91,   3,  68,  68,  92,  92,  95,  93,  94,
  94,  96,  96,  11,  69,  69,  97,  20,  20,  71,
  21,  21,  22,  22,  38,  38,  38,  39,  39,  39,
  39,  39,  39,  39,  39,  39,  39,  39,  39,  39,
  39,  12,  12,  13,  13,  13,  13,  13,  13,  37,
  37,  37,  37,  32,  40,  40,  44,  44,  48,  48,
  48,  48,  48,  48,  48,  47,  49,  49,  49,  41,
  41,  42,  42,  42,  42,  42,  42,  42,  42,  58,
  58,  58,  58,  58,  58,  58,  58,  58,  99,  23,
  24,  24,  98,  98,  98,  98,  98,  98,  98,  98,
  98,  98,  98,   4, 100, 101, 101, 101, 101,  73,
  73,  35,  25,  25,  46,  46,  14,  14,  28,  28,
  59,  78,  79, 102, 103, 103, 103, 103, 103, 103,
 103, 103, 103, 103, 103, 103, 103, 103, 104, 111,
 111, 111, 106, 113, 113, 113, 108, 108, 105, 105,
 114, 114, 115, 115, 115, 115, 115, 115,  15, 107,
 109, 110, 110,  29,  29,   6,   6,  30,  30,  30,
  31,  31,  31,  31,  31,  31,   5,   5,   5,   5,
   5, 112
};
short	yyr2[] =
{
   0,   0,   3,   2,   2,   2,   3,   3,   2,   1,
   1,   3,   4,   3,   4,   4,   5,   3,   0,   1,
   1,   0,   1,   2,   3,   1,   3,   1,   3,   0,
   2,   3,   1,   3,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   2,   1,   5,   7,
   5,   5,   0,   2,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   0,   4,   6,
   3,   4,   5,   3,   1,   3,   3,   3,   3,   3,
   3,   3,   3,   1,   3,   3,   3,   0,   6,   0,
   0,   0,   2,   3,   1,   3,   1,   2,   1,   1,
   3,   1,   1,   1,   3,   3,   2,   1,   5,   1,
   3,   0,   3,   0,   2,   3,   1,   3,   1,   1,
   1,   3,   1,   3,   3,   4,   1,   0,   2,   1,
   3,   1,   3,   1,   1,   2,   4,   1,   3,   0,
   0,   1,   1,   3,   1,   3,   1,   1,   1,   3,
   3,   3,   3,   2,   3,   3,   3,   3,   3,   2,
   3,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   2,   4,   5,   5,   0,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   5,   1,   1,   1,   1,
   3,   1,   1,   3,   3,   3,   3,   2,   3,   1,
   5,   4,   1,   2,   2,   6,   2,   2,   5,   3,
   1,   4,   4,   5,   2,   1,   1,  10,   1,   3,
   4,   3,   3,   1,   1,   3,   3,   7,   7,   0,
   1,   3,   1,   3,   1,   2,   1,   1,   1,   3,
   0,   0,   0,   1,   2,   2,   2,   2,   2,   2,
   2,   3,   4,   4,   2,   3,   1,   3,   3,   1,
   1,   1,   3,   1,   1,   1,   1,   1,   3,   3,
   1,   3,   1,   1,   1,   2,   2,   2,   1,   3,
   3,   4,   4,   1,   3,   1,   5,   1,   1,   1,
   3,   3,   3,   3,   3,   3,   1,   3,   5,   5,
   5,   0
};
short	yychk[] =
{
-1000,  -1, -55,  -2,   2,   6,   4, -56, -57, -58,
  21,  40,   7,  63,  26,  72,  47,  -7,  43, -10,
 -50, -64, -65, -66, -67, -68, -69,  69,  46,  60,
 -98,  36, 100, -99,  39,  38,  42,  -8,  30,  45,
  56,  44,  33,  53,  58,-100,  23,  32,-101,-102,
  51, -35,  67, -14,  52,  -9,  22,  48,  49,  50,
-103,  27,  61,  71,  55,  66,  31,  37,  34,  57,
  28,  75,  35,  24,  70, 103,-104,-106,-107,-109,
-110,-111,-113,  65,  76,  62,  25,  68,  41,  54,
  59,  29, -17,   8, -59, -60, -60, -60, -60,  47,
 -73,  81, -52, -33,  17,  81, 102, -73,  81,  81,
  81,  81, -73,  81, -97,  86, -70, -86, -33, -51,
  88,  86, -71, -59, -98,  73, -59, -59, -59, -16,
  85, -71, -71, -71, -71, -81, -71, -37, -33, -59,
 -59, -59,  77, -59, -59, -59, -59, -59, -59, -59,
-105, -42,  85,  87,  77, -37, -48, -41, -12,  15,
  16,   8,   9,  10,  11, -49,  83,  84,  14,  13,
  12,-105,  77,-105,-108, -42,  85,-105,  81, -59,
 -59, -59, -59, -59, -53, -52, -53, -52, -52, -60,
 -33, -26,  77, -33, -76, -51, -36, -33, -33, -33,
 -80,  77, -82, -76, -92, -93, -95, -33,  81,  17,
  77,  -3, -73,   9,  77, -78, -36, -51, -33, -33,
 -80, -82, -92,  79, -32,  77,  -4,   9,  77,  78,
 -25, -46, -38,  85, -39,  77, -47, -37, -48, -12,
  93, -40, -38, -40,  77,  -3, -33,  77, -33, -41,
-114, -42,  77,-115,  85,  87, -15,  18, -12,  85,
  86,  87,  88, -41, -41, -29,  81,  -6, -37,  77,
  81, -30, -39,  -5, -31, -38, -47,  77, -30,-112,
-112,-112,-112, -41,  85, -61,  77, -26, -26, -52,
 -71,  78, -27, -34, -33,  85, -75,  77, -77, -84,
 -73, -75, -54, -37, -19, -18, -37,  77,  77,  -7,
  86, -86,  86, -72, -87, -33, -73, -24, -23, 101,
 -33, -38, -38,  77, -36, -38, -21, -40, -22, -38,
  74, -38,  78,  81, -12,  85,  86,  87, -13,  92,
  91,  90,  89,  88,  94,  96,  95,  98,  97,  99,
  -3, -38, -39, -38, -38, -38, -73, -91,  -3,  78,
  78,  81, -41, -38,  85,  87, -41, -41, -41, -41,
 -41,  78,  81, -29, -29, -29,  81,  81,  81, -38,
 -39,  -5, -31,-112,-112,  78, -62, -63,  17, -26,
 -74,  78,  81, -16, -88, -89, 102,  81, -85, -45,
 -44, -12, -47, -33, -48,  77, -36,  78,  81,  86,
  81, -19, -94, -96, -11,  17, -20, -33,  78,  81,
  79, -24,  77,  79,  78, -79,  85,  78,  80,  81,
 -33,  78, -46, -38, -38, -38, -38, -38, -38, -38,
 -38, -38, -38,  78,  81,  78,  77,  81,  78,-115,
 -41,  78,  -6,  81, -39,  -5, -39,  -5, -39,  -5,
  78,  81,  81,  81,  78,  81,  79, -75, -34,  78,
  81, -90, -43, -38,  85, -85,  85, -44, -37, -83,
 -18,  81,  78,  81,  84,  81, -87, -38, -38, -28,
 -38,  73,  78, -32,  77, -40, -38,  -3, -39, -91,
  -3, -73, -23, -33, -39, -23, -23, -23, -63,  17,
 -16, -90,  80, -45, -44, -77, -23, -96, -11, -33,
  78,  81, -79,  78,  81,  78,  78, -38,  78,  78,
  78,  78, -43, -38,  86,  78, -38,  -3,  81,  -3
};
short	yydef[] =
{
   1,  -2,   0,   0,   9,  10,   2,   3,   4,   5,
   0, 240,   8,  18,  18,  18,  18, 229,   0,  37,
  -2,  39,  40,  41,  -2,  43,  44,  45,  47, 139,
 199, 240, 202,   0, 240, 240, 240,  67, 139, 139,
 139, 139,  87, 139, 134,   0, 240, 240, 215, 216,
 240, 218, 240, 240, 240,  54, 224, 240, 240, 240,
 243, 240, 236, 237,  55,  56,  57,  58,  59,  60,
  61,  62,  63,  64,  65,  66,   0,   0,   0,   0,
 256, 240, 240, 240, 240, 240, 259, 260, 261, 263,
 264, 265,   6,  36,   7,  21,  21,   0,   0,  18,
   0, 230,  29,  19,  20,   0,  89,   0, 230,   0,
   0,   0,  89, 127, 135,   0,  46,  99, 101, 102,
  74,   0,   0, 229, 203, 204,   0, 206, 207,  53,
 241,   0,   0,   0,   0,  89, 127,   0, 169,   0,
 214,   0,   0, 174, 174,   0,   0,   0,   0,   0,
 244,  -2, 246, 247,   0, 191, 192,   0,   0, 178,
 179, 180, 181, 182, 183, 184, 161, 162, 186, 187,
 188, 248,   0, 249, 250,  -2, 267, 254,   0, 301,
 301, 301, 301,   0,  11,  22,  13,  29,  29,   0,
 139,  17,   0, 111,  91, 229,  73, 111,  77,  79,
  81,   0,  86,   0, 124, 126,   0,   0,   0,   0,
   0, 229,   0, 122,   0,   0,  70,   0,  76,  78,
  80,  85, 123,   0, 170,  -2,   0, 223,   0, 219,
   0, 232, 234,   0, 144,   0, 146, 147, 148,   0,
   0, 221, 175, 222,   0, 225,  -2,   0, 231, 272,
   0, 189,   0, 270, 273, 274,   0, 278,   0,   0,
   0,   0,   0, 197, 272, 251,   0, 283, 285,   0,
   0, 255,  -2, 288, 289,   0,  -2,   0, 257, 258,
 262, 279, 280, 301, 301,  12,   0,  14,  15,  29,
  52,  30,   0,  32,  34,  35,  67, 113,   0,   0,
   0, 106,   0,  83,   0, 109, 107,   0,   0, 128,
   0, 100,  75,   0, 103,   0,   0, 201, 210,   0,
   0,   0, 242,   0,  71, 212,   0,   0, 141,  -2,
   0,   0, 220,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0, 163, 164, 165, 166, 167, 168,
 235,   0, 144, 153, 159,   0,   0,   0, 120,  -2,
 269,   0,   0, 275, 276, 277, 193, 194, 195, 196,
 198, 268,   0, 253,   0, 252,   0,   0,   0,   0,
 144,   0,   0, 281, 282,  23,   0,  25,  27,  16,
 111,  31,   0,  50,   0,   0,  51,   0,  92,  94,
  96,   0,  98, 176, 177,   0,  72,  82,   0,  90,
   0,   0,   0, 129, 131, 133, 136, 137,  48,   0,
   0, 200,   0,   0,   0,  68,   0, 171, 174,   0,
 213,   0, 233, 149, 150, 151, 152,  -2, 155, 156,
 157, 158, 160, 145,   0, 208,   0,   0, 229, 271,
 272, 190, 284,   0,  -2, 291,  -2, 293,  -2, 295,
  -2,   0,   0,   0,  24,   0,   0,  67,  33, 112,
   0, 114, 116, 119, 118,  93,   0,  97,  84,  91,
 110,   0, 125,   0,   0,   0, 104, 105,   0, 209,
 238, 205, 242, 172, 174,   0, 143,   0, 144,   0,
 121,   0,   0, 169,  -2,   0,   0,   0,  26,  28,
  49, 115,   0,  95,  96,   0,   0, 130, 132, 138,
 211,   0,  69, 173,   0, 185, 227, 228, 286, 298,
 299, 300, 117, 119,  88, 108, 239,   0,   0, 217
};
short	yytok1[] =
{
   1,   4,   5,   6,   7,   8,   9,  10,  11,  12,
  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,
  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,
  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,
  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,
  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,
  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,
  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,
  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,
  93,  94,  95,  96,  97,  98,  99, 100, 101, 102,
 103
};
short	yytok2[] =
{
   2,   3
};
long	yytok3[] =
{
   0
};
#define YYFLAG 		-1000
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define	yyclearin	yychar = -1
#define	yyerrok		yyerrflag = 0

#ifdef	yydebug
#include	"y.debug"
#else
#define	yydebug		0
char*	yytoknames[1];		/* for debugging */
char*	yystates[1];		/* for debugging */
#endif

/*	parser for yacc output	*/

int	yynerrs = 0;		/* number of errors */
int	yyerrflag = 0;		/* error recovery flag */

extern	int	fprint(int, char*, ...);
extern	int	sprint(char*, char*, ...);

char*
yytokname(int yyc)
{
	static char x[10];

	if(yyc > 0 && yyc <= sizeof(yytoknames)/sizeof(yytoknames[0]))
	if(yytoknames[yyc-1])
		return yytoknames[yyc-1];
	sprintf(x, "<%d>", yyc);
	return x;
}

char*
yystatname(int yys)
{
	static char x[10];

	if(yys >= 0 && yys < sizeof(yystates)/sizeof(yystates[0]))
	if(yystates[yys])
		return yystates[yys];
	sprintf(x, "<%d>\n", yys);
	return x;
}

long
yylex1(void)
{
	long yychar;
	long *t3p;
	int c;

	yychar = yylex();
	if(yychar <= 0) {
		c = yytok1[0];
		goto out;
	}
	if(yychar < sizeof(yytok1)/sizeof(yytok1[0])) {
		c = yytok1[yychar];
		goto out;
	}
	if(yychar >= YYPRIVATE)
		if(yychar < YYPRIVATE+sizeof(yytok2)/sizeof(yytok2[0])) {
			c = yytok2[yychar-YYPRIVATE];
			goto out;
		}
	for(t3p=yytok3;; t3p+=2) {
		c = t3p[0];
		if(c == yychar) {
			c = t3p[1];
			goto out;
		}
		if(c == 0)
			break;
	}
	c = 0;

out:
	if(c == 0)
		c = yytok2[1];	/* unknown char */
	if(yydebug >= 3)
		printf("lex %.4X %s\n", yychar, yytokname(c));
	return c;
}

int
yyparse(void)
{
	struct
	{
		YYSTYPE	yyv;
		int	yys;
	} yys[YYMAXDEPTH], *yyp, *yypt;
	short *yyxi;
	int yyj, yym, yystate, yyn, yyg;
	YYSTYPE save1, save2;
	int save3, save4;
	long yychar;

	save1 = yylval;
	save2 = yyval;
	save3 = yynerrs;
	save4 = yyerrflag;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyp = &yys[-1];
	goto yystack;

ret0:
	yyn = 0;
	goto ret;

ret1:
	yyn = 1;
	goto ret;

ret:
	yylval = save1;
	yyval = save2;
	yynerrs = save3;
	yyerrflag = save4;
	return yyn;

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 4)
		printf("char %s in %s", yytokname(yychar), yystatname(yystate));

	yyp++;
	if(yyp >= &yys[YYMAXDEPTH]) { 
		yyerror("yacc stack overflow"); 
		goto ret1; 
	}
	yyp->yys = yystate;
	yyp->yyv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0)
		yychar = yylex1();
	yyn += yychar;
	if(yyn < 0 || yyn >= YYLAST)
		goto yydefault;
	yyn = yyact[yyn];
	if(yychk[yyn] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			yyerrflag--;
		goto yystack;
	}

yydefault:
	/* default state action */
	yyn = yydef[yystate];
	if(yyn == -2) {
		if(yychar < 0)
			yychar = yylex1();

		/* look through exception table */
		for(yyxi=yyexca;; yyxi+=2)
			if(yyxi[0] == -1 && yyxi[1] == yystate)
				break;
		for(yyxi += 2;; yyxi += 2) {
			yyn = yyxi[0];
			if(yyn < 0 || yyn == yychar)
				break;
		}
		yyn = yyxi[1];
		if(yyn < 0)
			goto ret0;
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			if(yydebug >= 1) {
				printf("%s", yystatname(yystate));
				printf("saw %s\n", yytokname(yychar));
			}
yyerrlab:
			yynerrs++;

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */
			while(yyp >= yys) {
				yyn = yypact[yyp->yys] + YYERRCODE;
				if(yyn >= 0 && yyn < YYLAST) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					if(yychk[yystate] == YYERRCODE)
						goto yystack;
				}

				/* the current yyp has no shift onn "error", pop stack */
				if(yydebug >= 2)
					printf("error recovery pops state %d, uncovers %d\n",
						yyp->yys, (yyp-1)->yys );
				yyp--;
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug >= YYEOFCODE)
				printf("error recovery discards %s\n", yytokname(yychar));
			if(yychar == YYEOFCODE)
				goto ret1;
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}

	/* reduction by production yyn */
	if(yydebug >= 2)
		printf("reduce %d in:\n\t%s", yyn, yystatname(yystate));

	yypt = yyp;
	yyp -= yyr2[yyn];
	yyval = (yyp+1)->yyv;
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyg = yypgo[yyn];
	yyj = yyg + yyp->yys + 1;

	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yyg];
	switch(yym) {
		
case 3:
/* #line	219	"gram.in" */
{
/* stat:   is the nonterminal for Fortran statements */

		  lastwasbranch = NO; } break;
case 5:
/* #line	225	"gram.in" */
{ /* forbid further statement function definitions... */
		  if (parstate == INDATA && laststfcn != thisstno)
			parstate = INEXEC;
		  thisstno++;
		  if(yypt[-1].yyv.labval && (yypt[-1].yyv.labval->labelno==dorange))
			enddo(yypt[-1].yyv.labval->labelno);
		  if(lastwasbranch && thislabel==NULL)
			warn("statement cannot be reached");
		  lastwasbranch = thiswasbranch;
		  thiswasbranch = NO;
		  if(yypt[-1].yyv.labval)
			{
			if(yypt[-1].yyv.labval->labtype == LABFORMAT)
				err("label already that of a format");
			else
				yypt[-1].yyv.labval->labtype = LABEXEC;
			}
		  freetemps();
		} break;
case 6:
/* #line	245	"gram.in" */
{ if (can_include)
			doinclude( yypt[-0].yyv.charpval );
		  else {
			fprintf(diagfile, "Cannot open file %s\n", yypt[-0].yyv.charpval);
			done(1);
			}
		} break;
case 7:
/* #line	253	"gram.in" */
{ if (yypt[-2].yyv.labval)
			lastwasbranch = NO;
		  endproc(); /* lastwasbranch = NO; -- set in endproc() */
		} break;
case 8:
/* #line	258	"gram.in" */
{ unclassifiable();

/* flline flushes the current line, ignoring the rest of the text there */

		  flline(); } break;
case 9:
/* #line	264	"gram.in" */
{ flline();  needkwd = NO;  inioctl = NO;
		  yyerrok; yyclearin; } break;
case 10:
/* #line	269	"gram.in" */
{
		if(yystno != 0)
			{
			yyval.labval = thislabel =  mklabel(yystno);
			if( ! headerdone ) {
				if (procclass == CLUNKNOWN)
					procclass = CLMAIN;
				puthead(CNULL, procclass);
				}
			if(thislabel->labdefined)
				execerr("label %s already defined",
					convic(thislabel->stateno) );
			else	{
				if(thislabel->blklevel!=0 && thislabel->blklevel<blklevel
				    && thislabel->labtype!=LABFORMAT)
					warn1("there is a branch to label %s from outside block",
					      convic( (ftnint) (thislabel->stateno) ) );
				thislabel->blklevel = blklevel;
				thislabel->labdefined = YES;
				if(thislabel->labtype != LABFORMAT)
					p1_label((long)(thislabel - labeltab));
				}
			}
		else    yyval.labval = thislabel = NULL;
		} break;
case 11:
/* #line	297	"gram.in" */
{startproc(yypt[-0].yyv.extval, CLMAIN); } break;
case 12:
/* #line	299	"gram.in" */
{	warn("ignoring arguments to main program");
			/* hashclear(); */
			startproc(yypt[-1].yyv.extval, CLMAIN); } break;
case 13:
/* #line	303	"gram.in" */
{ if(yypt[-0].yyv.extval) NO66("named BLOCKDATA");
		  startproc(yypt[-0].yyv.extval, CLBLOCK); } break;
case 14:
/* #line	306	"gram.in" */
{ entrypt(CLPROC, TYSUBR, (ftnint) 0,  yypt[-1].yyv.extval, yypt[-0].yyv.chval); } break;
case 15:
/* #line	308	"gram.in" */
{ entrypt(CLPROC, TYUNKNOWN, (ftnint) 0, yypt[-1].yyv.extval, yypt[-0].yyv.chval); } break;
case 16:
/* #line	310	"gram.in" */
{ entrypt(CLPROC, yypt[-4].yyv.ival, varleng, yypt[-1].yyv.extval, yypt[-0].yyv.chval); } break;
case 17:
/* #line	312	"gram.in" */
{ if(parstate==OUTSIDE || procclass==CLMAIN
			|| procclass==CLBLOCK)
				execerr("misplaced entry statement", CNULL);
		  entrypt(CLENTRY, 0, (ftnint) 0, yypt[-1].yyv.extval, yypt[-0].yyv.chval);
		} break;
case 18:
/* #line	320	"gram.in" */
{ newproc(); } break;
case 19:
/* #line	324	"gram.in" */
{ yyval.extval = newentry(yypt[-0].yyv.namval, 1); } break;
case 20:
/* #line	328	"gram.in" */
{ yyval.namval = mkname(token); } break;
case 21:
/* #line	331	"gram.in" */
{ yyval.extval = NULL; } break;
case 29:
/* #line	349	"gram.in" */
{ yyval.chval = 0; } break;
case 30:
/* #line	351	"gram.in" */
{ NO66(" () argument list");
		  yyval.chval = 0; } break;
case 31:
/* #line	354	"gram.in" */
{yyval.chval = yypt[-1].yyv.chval; } break;
case 32:
/* #line	358	"gram.in" */
{ yyval.chval = (yypt[-0].yyv.namval ? mkchain((char *)yypt[-0].yyv.namval,CHNULL) : CHNULL ); } break;
case 33:
/* #line	360	"gram.in" */
{ if(yypt[-0].yyv.namval) yypt[-2].yyv.chval = yyval.chval = mkchain((char *)yypt[-0].yyv.namval, yypt[-2].yyv.chval); } break;
case 34:
/* #line	364	"gram.in" */
{ if(yypt[-0].yyv.namval->vstg!=STGUNKNOWN && yypt[-0].yyv.namval->vstg!=STGARG)
			dclerr("name declared as argument after use", yypt[-0].yyv.namval);
		  yypt[-0].yyv.namval->vstg = STGARG;
		} break;
case 35:
/* #line	369	"gram.in" */
{ NO66("altenate return argument");

/* substars   means that '*'ed formal parameters should be replaced.
   This is used to specify alternate return labels; in theory, only
   parameter slots which have '*' should accept the statement labels.
   This compiler chooses to ignore the '*'s in the formal declaration, and
   always return the proper value anyway.

   This variable is only referred to in   proc.c   */

		  yyval.namval = 0;  substars = YES; } break;
case 36:
/* #line	385	"gram.in" */
{
		char *s;
		s = copyn(toklen+1, token);
		s[toklen] = '\0';
		yyval.charpval = s;
		} break;
case 45:
/* #line	401	"gram.in" */
{ NO66("SAVE statement");
		  saveall = YES; } break;
case 46:
/* #line	404	"gram.in" */
{ NO66("SAVE statement"); } break;
case 47:
/* #line	406	"gram.in" */
{ fmtstmt(thislabel); setfmt(thislabel); } break;
case 48:
/* #line	408	"gram.in" */
{ NO66("PARAMETER statement"); } break;
case 49:
/* #line	412	"gram.in" */
{ settype(yypt[-4].yyv.namval, yypt[-6].yyv.ival, yypt[-0].yyv.lval);
		  if(ndim>0) setbound(yypt[-4].yyv.namval,ndim,dims);
		} break;
case 50:
/* #line	416	"gram.in" */
{ settype(yypt[-2].yyv.namval, yypt[-4].yyv.ival, yypt[-0].yyv.lval);
		  if(ndim>0) setbound(yypt[-2].yyv.namval,ndim,dims);
		} break;
case 51:
/* #line	420	"gram.in" */
{ if (new_dcl == 2) {
			err("attempt to give DATA in type-declaration");
			new_dcl = 1;
			}
		} break;
case 52:
/* #line	427	"gram.in" */
{ new_dcl = 2; } break;
case 53:
/* #line	430	"gram.in" */
{ varleng = yypt[-0].yyv.lval; } break;
case 54:
/* #line	434	"gram.in" */
{ varleng = (yypt[-0].yyv.ival<0 || ONEOF(yypt[-0].yyv.ival,M(TYLOGICAL)|M(TYLONG))
				? 0 : typesize[yypt[-0].yyv.ival]);
		  vartype = yypt[-0].yyv.ival; } break;
case 55:
/* #line	439	"gram.in" */
{ yyval.ival = TYLONG; } break;
case 56:
/* #line	440	"gram.in" */
{ yyval.ival = tyreal; } break;
case 57:
/* #line	441	"gram.in" */
{ ++complex_seen; yyval.ival = tycomplex; } break;
case 58:
/* #line	442	"gram.in" */
{ yyval.ival = TYDREAL; } break;
case 59:
/* #line	443	"gram.in" */
{ ++dcomplex_seen; NOEXT("DOUBLE COMPLEX statement"); yyval.ival = TYDCOMPLEX; } break;
case 60:
/* #line	444	"gram.in" */
{ yyval.ival = TYLOGICAL; } break;
case 61:
/* #line	445	"gram.in" */
{ NO66("CHARACTER statement"); yyval.ival = TYCHAR; } break;
case 62:
/* #line	446	"gram.in" */
{ yyval.ival = TYUNKNOWN; } break;
case 63:
/* #line	447	"gram.in" */
{ yyval.ival = TYUNKNOWN; } break;
case 64:
/* #line	448	"gram.in" */
{ NOEXT("AUTOMATIC statement"); yyval.ival = - STGAUTO; } break;
case 65:
/* #line	449	"gram.in" */
{ NOEXT("STATIC statement"); yyval.ival = - STGBSS; } break;
case 66:
/* #line	450	"gram.in" */
{ yyval.ival = TYINT1; } break;
case 67:
/* #line	454	"gram.in" */
{ yyval.lval = varleng; } break;
case 68:
/* #line	456	"gram.in" */
{
		expptr p;
		p = yypt[-1].yyv.expval;
		NO66("length specification *n");
		if( ! ISICON(p) || p->constblock.Const.ci <= 0 )
			{
			yyval.lval = 0;
			dclerr("length must be a positive integer constant",
				NPNULL);
			}
		else {
			if (vartype == TYCHAR)
				yyval.lval = p->constblock.Const.ci;
			else switch((int)p->constblock.Const.ci) {
				case 1:	yyval.lval = 1; break;
				case 2: yyval.lval = typesize[TYSHORT];	break;
				case 4: yyval.lval = typesize[TYLONG];	break;
				case 8: yyval.lval = typesize[TYDREAL];	break;
				case 16: yyval.lval = typesize[TYDCOMPLEX]; break;
				default:
					dclerr("invalid length",NPNULL);
					yyval.lval = varleng;
				}
			}
		} break;
case 69:
/* #line	482	"gram.in" */
{ NO66("length specification *(*)"); yyval.lval = -1; } break;
case 70:
/* #line	486	"gram.in" */
{ incomm( yyval.extval = comblock("") , yypt[-0].yyv.namval ); } break;
case 71:
/* #line	488	"gram.in" */
{ yyval.extval = yypt[-1].yyv.extval;  incomm(yypt[-1].yyv.extval, yypt[-0].yyv.namval); } break;
case 72:
/* #line	490	"gram.in" */
{ yyval.extval = yypt[-2].yyv.extval;  incomm(yypt[-2].yyv.extval, yypt[-0].yyv.namval); } break;
case 73:
/* #line	492	"gram.in" */
{ incomm(yypt[-2].yyv.extval, yypt[-0].yyv.namval); } break;
case 74:
/* #line	496	"gram.in" */
{ yyval.extval = comblock(""); } break;
case 75:
/* #line	498	"gram.in" */
{ yyval.extval = comblock(token); } break;
case 76:
/* #line	502	"gram.in" */
{ setext(yypt[-0].yyv.namval); } break;
case 77:
/* #line	504	"gram.in" */
{ setext(yypt[-0].yyv.namval); } break;
case 78:
/* #line	508	"gram.in" */
{ NO66("INTRINSIC statement"); setintr(yypt[-0].yyv.namval); } break;
case 79:
/* #line	510	"gram.in" */
{ setintr(yypt[-0].yyv.namval); } break;
case 82:
/* #line	518	"gram.in" */
{
		struct Equivblock *p;
		if(nequiv >= maxequiv)
			many("equivalences", 'q', maxequiv);
		p  =  & eqvclass[nequiv++];
		p->eqvinit = NO;
		p->eqvbottom = 0;
		p->eqvtop = 0;
		p->equivs = yypt[-1].yyv.eqvval;
		} break;
case 83:
/* #line	531	"gram.in" */
{ yyval.eqvval=ALLOC(Eqvchain);
		  yyval.eqvval->eqvitem.eqvlhs = primchk(yypt[-0].yyv.expval);
		} break;
case 84:
/* #line	535	"gram.in" */
{ yyval.eqvval=ALLOC(Eqvchain);
		  yyval.eqvval->eqvitem.eqvlhs = primchk(yypt[-0].yyv.expval);
		  yyval.eqvval->eqvnextp = yypt[-2].yyv.eqvval;
		} break;
case 87:
/* #line	546	"gram.in" */
{ if(parstate == OUTSIDE)
			{
			newproc();
			startproc(ESNULL, CLMAIN);
			}
		  if(parstate < INDATA)
			{
			enddcl();
			parstate = INDATA;
			datagripe = 1;
			}
		} break;
case 88:
/* #line	561	"gram.in" */
{ ftnint junk;
		  if(nextdata(&junk) != NULL)
			err("too few initializers");
		  frdata(yypt[-4].yyv.chval);
		  frrpl();
		} break;
case 89:
/* #line	569	"gram.in" */
{ frchain(&datastack); curdtp = 0; } break;
case 90:
/* #line	571	"gram.in" */
{ pop_datastack(); } break;
case 91:
/* #line	573	"gram.in" */
{ toomanyinit = NO; } break;
case 94:
/* #line	578	"gram.in" */
{ dataval(ENULL, yypt[-0].yyv.expval); } break;
case 95:
/* #line	580	"gram.in" */
{ dataval(yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 97:
/* #line	585	"gram.in" */
{ if( yypt[-1].yyv.ival==OPMINUS && ISCONST(yypt[-0].yyv.expval) )
			consnegop((Constp)yypt[-0].yyv.expval);
		  yyval.expval = yypt[-0].yyv.expval;
		} break;
case 101:
/* #line	597	"gram.in" */
{ int k;
		  yypt[-0].yyv.namval->vsave = YES;
		  k = yypt[-0].yyv.namval->vstg;
		if( ! ONEOF(k, M(STGUNKNOWN)|M(STGBSS)|M(STGINIT)) )
			dclerr("can only save static variables", yypt[-0].yyv.namval);
		} break;
case 105:
/* #line	611	"gram.in" */
{ if(yypt[-2].yyv.namval->vclass == CLUNKNOWN)
			make_param((struct Paramblock *)yypt[-2].yyv.namval, yypt[-0].yyv.expval);
		  else dclerr("cannot make into parameter", yypt[-2].yyv.namval);
		} break;
case 106:
/* #line	618	"gram.in" */
{ if(ndim>0) setbound(yypt[-1].yyv.namval, ndim, dims); } break;
case 107:
/* #line	622	"gram.in" */
{ Namep np;
		  struct Primblock *pp = (struct Primblock *)yypt[-0].yyv.expval;
		  int tt = yypt[-0].yyv.expval->tag;
		  if (tt != TPRIM) {
			if (tt == TCONST)
				err("parameter in data statement");
			else
				erri("tag %d in data statement",tt);
			yyval.chval = 0;
			err_lineno = lineno;
			break;
			}
		  np = pp -> namep;
		  vardcl(np);
		  if ((pp->fcharp || pp->lcharp)
		   && (np->vtype != TYCHAR || np->vdim && !pp->argsp))
			sserr(np);
		  if(np->vstg == STGCOMMON)
			extsymtab[np->vardesc.varno].extinit = YES;
		  else if(np->vstg==STGEQUIV)
			eqvclass[np->vardesc.varno].eqvinit = YES;
		  else if(np->vstg!=STGINIT && np->vstg!=STGBSS) {
			errstr(np->vstg == STGARG
				? "Dummy argument \"%.60s\" in data statement."
				: "Cannot give data to \"%.75s\"",
				np->fvarname);
			yyval.chval = 0;
			err_lineno = lineno;
			break;
			}
		  yyval.chval = mkchain((char *)yypt[-0].yyv.expval, CHNULL);
		} break;
case 108:
/* #line	655	"gram.in" */
{ chainp p; struct Impldoblock *q;
		pop_datastack();
		q = ALLOC(Impldoblock);
		q->tag = TIMPLDO;
		(q->varnp = (Namep) (yypt[-1].yyv.chval->datap))->vimpldovar = 1;
		p = yypt[-1].yyv.chval->nextp;
		if(p)  { q->implb = (expptr)(p->datap); p = p->nextp; }
		if(p)  { q->impub = (expptr)(p->datap); p = p->nextp; }
		if(p)  { q->impstep = (expptr)(p->datap); }
		frchain( & (yypt[-1].yyv.chval) );
		yyval.chval = mkchain((char *)q, CHNULL);
		q->datalist = hookup(yypt[-3].yyv.chval, yyval.chval);
		} break;
case 109:
/* #line	671	"gram.in" */
{ if (!datastack)
			curdtp = 0;
		  datastack = mkchain((char *)curdtp, datastack);
		  curdtp = yypt[-0].yyv.chval; curdtelt = 0;
		  } break;
case 110:
/* #line	677	"gram.in" */
{ yyval.chval = hookup(yypt[-2].yyv.chval, yypt[-0].yyv.chval); } break;
case 111:
/* #line	681	"gram.in" */
{ ndim = 0; } break;
case 113:
/* #line	685	"gram.in" */
{ ndim = 0; } break;
case 116:
/* #line	690	"gram.in" */
{
		  if(ndim == maxdim)
			err("too many dimensions");
		  else if(ndim < maxdim)
			{ dims[ndim].lb = 0;
			  dims[ndim].ub = yypt[-0].yyv.expval;
			}
		  ++ndim;
		} break;
case 117:
/* #line	700	"gram.in" */
{
		  if(ndim == maxdim)
			err("too many dimensions");
		  else if(ndim < maxdim)
			{ dims[ndim].lb = yypt[-2].yyv.expval;
			  dims[ndim].ub = yypt[-0].yyv.expval;
			}
		  ++ndim;
		} break;
case 118:
/* #line	712	"gram.in" */
{ yyval.expval = 0; } break;
case 120:
/* #line	717	"gram.in" */
{ nstars = 1; labarray[0] = yypt[-0].yyv.labval; } break;
case 121:
/* #line	719	"gram.in" */
{ if(nstars < maxlablist)  labarray[nstars++] = yypt[-0].yyv.labval; } break;
case 122:
/* #line	723	"gram.in" */
{ yyval.labval = execlab( convci(toklen, token) ); } break;
case 123:
/* #line	727	"gram.in" */
{ NO66("IMPLICIT statement"); } break;
case 126:
/* #line	733	"gram.in" */
{ if (vartype != TYUNKNOWN)
			dclerr("-- expected letter range",NPNULL);
		  setimpl(vartype, varleng, 'a', 'z'); } break;
case 127:
/* #line	738	"gram.in" */
{ needkwd = 1; } break;
case 131:
/* #line	747	"gram.in" */
{ setimpl(vartype, varleng, yypt[-0].yyv.ival, yypt[-0].yyv.ival); } break;
case 132:
/* #line	749	"gram.in" */
{ setimpl(vartype, varleng, yypt[-2].yyv.ival, yypt[-0].yyv.ival); } break;
case 133:
/* #line	753	"gram.in" */
{ if(toklen!=1 || token[0]<'a' || token[0]>'z')
			{
			dclerr("implicit item must be single letter", NPNULL);
			yyval.ival = 0;
			}
		  else yyval.ival = token[0];
		} break;
case 136:
/* #line	767	"gram.in" */
{
		if(yypt[-2].yyv.namval->vclass == CLUNKNOWN)
			{
			yypt[-2].yyv.namval->vclass = CLNAMELIST;
			yypt[-2].yyv.namval->vtype = TYINT;
			yypt[-2].yyv.namval->vstg = STGBSS;
			yypt[-2].yyv.namval->varxptr.namelist = yypt[-0].yyv.chval;
			yypt[-2].yyv.namval->vardesc.varno = ++lastvarno;
			}
		else dclerr("cannot be a namelist name", yypt[-2].yyv.namval);
		} break;
case 137:
/* #line	781	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.namval, CHNULL); } break;
case 138:
/* #line	783	"gram.in" */
{ yyval.chval = hookup(yypt[-2].yyv.chval, mkchain((char *)yypt[-0].yyv.namval, CHNULL)); } break;
case 139:
/* #line	787	"gram.in" */
{ switch(parstate)
			{
			case OUTSIDE:	newproc();
					startproc(ESNULL, CLMAIN);
			case INSIDE:	parstate = INDCL;
			case INDCL:	break;

			case INDATA:
				if (datagripe) {
					errstr(
				"Statement order error: declaration after DATA",
						CNULL);
					datagripe = 0;
					}
				break;

			default:
				dclerr("declaration among executables", NPNULL);
			}
		} break;
case 140:
/* #line	809	"gram.in" */
{ yyval.chval = 0; } break;
case 141:
/* #line	811	"gram.in" */
{ yyval.chval = revchain(yypt[-0].yyv.chval); } break;
case 142:
/* #line	815	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, CHNULL); } break;
case 143:
/* #line	817	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, yypt[-2].yyv.chval); } break;
case 145:
/* #line	822	"gram.in" */
{ yyval.expval = yypt[-1].yyv.expval; if (yyval.expval->tag == TPRIM)
					yyval.expval->primblock.parenused = 1; } break;
case 149:
/* #line	830	"gram.in" */
{ yyval.expval = mkexpr(yypt[-1].yyv.ival, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 150:
/* #line	832	"gram.in" */
{ yyval.expval = mkexpr(OPSTAR, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 151:
/* #line	834	"gram.in" */
{ yyval.expval = mkexpr(OPSLASH, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 152:
/* #line	836	"gram.in" */
{ yyval.expval = mkexpr(OPPOWER, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 153:
/* #line	838	"gram.in" */
{ if(yypt[-1].yyv.ival == OPMINUS)
			yyval.expval = mkexpr(OPNEG, yypt[-0].yyv.expval, ENULL);
		  else 	yyval.expval = yypt[-0].yyv.expval;
		} break;
case 154:
/* #line	843	"gram.in" */
{ yyval.expval = mkexpr(yypt[-1].yyv.ival, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 155:
/* #line	845	"gram.in" */
{ NO66(".EQV. operator");
		  yyval.expval = mkexpr(OPEQV, yypt[-2].yyv.expval,yypt[-0].yyv.expval); } break;
case 156:
/* #line	848	"gram.in" */
{ NO66(".NEQV. operator");
		  yyval.expval = mkexpr(OPNEQV, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 157:
/* #line	851	"gram.in" */
{ yyval.expval = mkexpr(OPOR, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 158:
/* #line	853	"gram.in" */
{ yyval.expval = mkexpr(OPAND, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 159:
/* #line	855	"gram.in" */
{ yyval.expval = mkexpr(OPNOT, yypt[-0].yyv.expval, ENULL); } break;
case 160:
/* #line	857	"gram.in" */
{ NO66("concatenation operator //");
		  yyval.expval = mkexpr(OPCONCAT, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 161:
/* #line	861	"gram.in" */
{ yyval.ival = OPPLUS; } break;
case 162:
/* #line	862	"gram.in" */
{ yyval.ival = OPMINUS; } break;
case 163:
/* #line	865	"gram.in" */
{ yyval.ival = OPEQ; } break;
case 164:
/* #line	866	"gram.in" */
{ yyval.ival = OPGT; } break;
case 165:
/* #line	867	"gram.in" */
{ yyval.ival = OPLT; } break;
case 166:
/* #line	868	"gram.in" */
{ yyval.ival = OPGE; } break;
case 167:
/* #line	869	"gram.in" */
{ yyval.ival = OPLE; } break;
case 168:
/* #line	870	"gram.in" */
{ yyval.ival = OPNE; } break;
case 169:
/* #line	874	"gram.in" */
{ yyval.expval = mkprim(yypt[-0].yyv.namval, LBNULL, CHNULL); } break;
case 170:
/* #line	876	"gram.in" */
{ NO66("substring operator :");
		  yyval.expval = mkprim(yypt[-1].yyv.namval, LBNULL, yypt[-0].yyv.chval); } break;
case 171:
/* #line	879	"gram.in" */
{ yyval.expval = mkprim(yypt[-3].yyv.namval, mklist(yypt[-1].yyv.chval), CHNULL); } break;
case 172:
/* #line	881	"gram.in" */
{ NO66("substring operator :");
		  yyval.expval = mkprim(yypt[-4].yyv.namval, mklist(yypt[-2].yyv.chval), yypt[-0].yyv.chval); } break;
case 173:
/* #line	886	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-3].yyv.expval, mkchain((char *)yypt[-1].yyv.expval,CHNULL)); } break;
case 174:
/* #line	890	"gram.in" */
{ yyval.expval = 0; } break;
case 176:
/* #line	895	"gram.in" */
{ if(yypt[-0].yyv.namval->vclass == CLPARAM)
			yyval.expval = (expptr) cpexpr(
				( (struct Paramblock *) (yypt[-0].yyv.namval) ) -> paramval);
		} break;
case 178:
/* #line	902	"gram.in" */
{ yyval.expval = mklogcon(1); } break;
case 179:
/* #line	903	"gram.in" */
{ yyval.expval = mklogcon(0); } break;
case 180:
/* #line	904	"gram.in" */
{ yyval.expval = mkstrcon(toklen, token); } break;
case 181:
/* #line	905	"gram.in" */
 { yyval.expval = mkintcon( convci(toklen, token) ); } break;
case 182:
/* #line	906	"gram.in" */
 { yyval.expval = mkrealcon(tyreal, token); } break;
case 183:
/* #line	907	"gram.in" */
 { yyval.expval = mkrealcon(TYDREAL, token); } break;
case 185:
/* #line	912	"gram.in" */
{ yyval.expval = mkcxcon(yypt[-3].yyv.expval,yypt[-1].yyv.expval); } break;
case 186:
/* #line	916	"gram.in" */
{ NOEXT("hex constant");
		  yyval.expval = mkbitcon(4, toklen, token); } break;
case 187:
/* #line	919	"gram.in" */
{ NOEXT("octal constant");
		  yyval.expval = mkbitcon(3, toklen, token); } break;
case 188:
/* #line	922	"gram.in" */
{ NOEXT("binary constant");
		  yyval.expval = mkbitcon(1, toklen, token); } break;
case 190:
/* #line	928	"gram.in" */
{ yyval.expval = yypt[-1].yyv.expval; } break;
case 193:
/* #line	934	"gram.in" */
{ yyval.expval = mkexpr(yypt[-1].yyv.ival, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 194:
/* #line	936	"gram.in" */
{ yyval.expval = mkexpr(OPSTAR, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 195:
/* #line	938	"gram.in" */
{ yyval.expval = mkexpr(OPSLASH, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 196:
/* #line	940	"gram.in" */
{ yyval.expval = mkexpr(OPPOWER, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 197:
/* #line	942	"gram.in" */
{ if(yypt[-1].yyv.ival == OPMINUS)
			yyval.expval = mkexpr(OPNEG, yypt[-0].yyv.expval, ENULL);
		  else	yyval.expval = yypt[-0].yyv.expval;
		} break;
case 198:
/* #line	947	"gram.in" */
{ NO66("concatenation operator //");
		  yyval.expval = mkexpr(OPCONCAT, yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 200:
/* #line	952	"gram.in" */
{
		if(yypt[-2].yyv.labval->labdefined)
			execerr("no backward DO loops", CNULL);
		yypt[-2].yyv.labval->blklevel = blklevel+1;
		exdo(yypt[-2].yyv.labval->labelno, NPNULL, yypt[-0].yyv.chval);
		} break;
case 201:
/* #line	959	"gram.in" */
{
		exdo((int)(ctls - ctlstack - 2), NPNULL, yypt[-0].yyv.chval);
		NOEXT("DO without label");
		} break;
case 202:
/* #line	964	"gram.in" */
{ exenddo(NPNULL); } break;
case 203:
/* #line	966	"gram.in" */
{ exendif();  thiswasbranch = NO; } break;
case 205:
/* #line	969	"gram.in" */
{ exelif(yypt[-2].yyv.expval); lastwasbranch = NO; } break;
case 206:
/* #line	971	"gram.in" */
{ exelse(); lastwasbranch = NO; } break;
case 207:
/* #line	973	"gram.in" */
{ exendif(); lastwasbranch = NO; } break;
case 208:
/* #line	977	"gram.in" */
{ exif(yypt[-1].yyv.expval); } break;
case 209:
/* #line	981	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-2].yyv.namval, yypt[-0].yyv.chval); } break;
case 211:
/* #line	986	"gram.in" */
{ yyval.chval = mkchain(CNULL, (chainp)yypt[-1].yyv.expval); } break;
case 212:
/* #line	990	"gram.in" */
{ exequals((struct Primblock *)yypt[-2].yyv.expval, yypt[-0].yyv.expval); } break;
case 213:
/* #line	992	"gram.in" */
{ exassign(yypt[-0].yyv.namval, yypt[-2].yyv.labval); } break;
case 216:
/* #line	996	"gram.in" */
{ inioctl = NO; } break;
case 217:
/* #line	998	"gram.in" */
{ exarif(yypt[-6].yyv.expval, yypt[-4].yyv.labval, yypt[-2].yyv.labval, yypt[-0].yyv.labval);  thiswasbranch = YES; } break;
case 218:
/* #line	1000	"gram.in" */
{ excall(yypt[-0].yyv.namval, LBNULL, 0, labarray); } break;
case 219:
/* #line	1002	"gram.in" */
{ excall(yypt[-2].yyv.namval, LBNULL, 0, labarray); } break;
case 220:
/* #line	1004	"gram.in" */
{ if(nstars < maxlablist)
			excall(yypt[-3].yyv.namval, mklist(revchain(yypt[-1].yyv.chval)), nstars, labarray);
		  else
			many("alternate returns", 'l', maxlablist);
		} break;
case 221:
/* #line	1010	"gram.in" */
{ exreturn(yypt[-0].yyv.expval);  thiswasbranch = YES; } break;
case 222:
/* #line	1012	"gram.in" */
{ exstop(yypt[-2].yyv.ival, yypt[-0].yyv.expval);  thiswasbranch = yypt[-2].yyv.ival; } break;
case 223:
/* #line	1016	"gram.in" */
{ yyval.labval = mklabel( convci(toklen, token) ); } break;
case 224:
/* #line	1020	"gram.in" */
{ if(parstate == OUTSIDE)
			{
			newproc();
			startproc(ESNULL, CLMAIN);
			}
		} break;
case 225:
/* #line	1029	"gram.in" */
{ exgoto(yypt[-0].yyv.labval);  thiswasbranch = YES; } break;
case 226:
/* #line	1031	"gram.in" */
{ exasgoto(yypt[-0].yyv.namval);  thiswasbranch = YES; } break;
case 227:
/* #line	1033	"gram.in" */
{ exasgoto(yypt[-4].yyv.namval);  thiswasbranch = YES; } break;
case 228:
/* #line	1035	"gram.in" */
{ if(nstars < maxlablist)
			putcmgo(putx(fixtype(yypt[-0].yyv.expval)), nstars, labarray);
		  else
			many("labels in computed GOTO list", 'l', maxlablist);
		} break;
case 231:
/* #line	1047	"gram.in" */
{ nstars = 0; yyval.namval = yypt[-0].yyv.namval; } break;
case 232:
/* #line	1051	"gram.in" */
{ yyval.chval = yypt[-0].yyv.expval ? mkchain((char *)yypt[-0].yyv.expval,CHNULL) : CHNULL; } break;
case 233:
/* #line	1053	"gram.in" */
{ yyval.chval = yypt[-0].yyv.expval ? mkchain((char *)yypt[-0].yyv.expval, yypt[-2].yyv.chval) : yypt[-2].yyv.chval; } break;
case 235:
/* #line	1058	"gram.in" */
{ if(nstars < maxlablist) labarray[nstars++] = yypt[-0].yyv.labval; yyval.expval = 0; } break;
case 236:
/* #line	1062	"gram.in" */
{ yyval.ival = 0; } break;
case 237:
/* #line	1064	"gram.in" */
{ yyval.ival = 2; } break;
case 238:
/* #line	1068	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, CHNULL); } break;
case 239:
/* #line	1070	"gram.in" */
{ yyval.chval = hookup(yypt[-2].yyv.chval, mkchain((char *)yypt[-0].yyv.expval,CHNULL) ); } break;
case 240:
/* #line	1074	"gram.in" */
{ if(parstate == OUTSIDE)
			{
			newproc();
			startproc(ESNULL, CLMAIN);
			}

/* This next statement depends on the ordering of the state table encoding */

		  if(parstate < INDATA) enddcl();
		} break;
case 241:
/* #line	1087	"gram.in" */
{ intonly = YES; } break;
case 242:
/* #line	1091	"gram.in" */
{ intonly = NO; } break;
case 243:
/* #line	1096	"gram.in" */
{ endio(); } break;
case 245:
/* #line	1101	"gram.in" */
{ ioclause(IOSUNIT, yypt[-0].yyv.expval); endioctl(); } break;
case 246:
/* #line	1103	"gram.in" */
{ ioclause(IOSUNIT, ENULL); endioctl(); } break;
case 247:
/* #line	1105	"gram.in" */
{ ioclause(IOSUNIT, IOSTDERR); endioctl(); } break;
case 249:
/* #line	1108	"gram.in" */
{ doio(CHNULL); } break;
case 250:
/* #line	1110	"gram.in" */
{ doio(CHNULL); } break;
case 251:
/* #line	1112	"gram.in" */
{ doio(revchain(yypt[-0].yyv.chval)); } break;
case 252:
/* #line	1114	"gram.in" */
{ doio(revchain(yypt[-0].yyv.chval)); } break;
case 253:
/* #line	1116	"gram.in" */
{ doio(revchain(yypt[-0].yyv.chval)); } break;
case 254:
/* #line	1118	"gram.in" */
{ doio(CHNULL); } break;
case 255:
/* #line	1120	"gram.in" */
{ doio(revchain(yypt[-0].yyv.chval)); } break;
case 256:
/* #line	1122	"gram.in" */
{ doio(CHNULL); } break;
case 257:
/* #line	1124	"gram.in" */
{ doio(revchain(yypt[-0].yyv.chval)); } break;
case 259:
/* #line	1131	"gram.in" */
{ iostmt = IOBACKSPACE; } break;
case 260:
/* #line	1133	"gram.in" */
{ iostmt = IOREWIND; } break;
case 261:
/* #line	1135	"gram.in" */
{ iostmt = IOENDFILE; } break;
case 263:
/* #line	1142	"gram.in" */
{ iostmt = IOINQUIRE; } break;
case 264:
/* #line	1144	"gram.in" */
{ iostmt = IOOPEN; } break;
case 265:
/* #line	1146	"gram.in" */
{ iostmt = IOCLOSE; } break;
case 266:
/* #line	1150	"gram.in" */
{
		ioclause(IOSUNIT, ENULL);
		ioclause(IOSFMT, yypt[-0].yyv.expval);
		endioctl();
		} break;
case 267:
/* #line	1156	"gram.in" */
{
		ioclause(IOSUNIT, ENULL);
		ioclause(IOSFMT, ENULL);
		endioctl();
		} break;
case 268:
/* #line	1164	"gram.in" */
{
		  ioclause(IOSUNIT, yypt[-1].yyv.expval);
		  endioctl();
		} break;
case 269:
/* #line	1169	"gram.in" */
{ endioctl(); } break;
case 272:
/* #line	1177	"gram.in" */
{ ioclause(IOSPOSITIONAL, yypt[-0].yyv.expval); } break;
case 273:
/* #line	1179	"gram.in" */
{ ioclause(IOSPOSITIONAL, ENULL); } break;
case 274:
/* #line	1181	"gram.in" */
{ ioclause(IOSPOSITIONAL, IOSTDERR); } break;
case 275:
/* #line	1183	"gram.in" */
{ ioclause(yypt[-1].yyv.ival, yypt[-0].yyv.expval); } break;
case 276:
/* #line	1185	"gram.in" */
{ ioclause(yypt[-1].yyv.ival, ENULL); } break;
case 277:
/* #line	1187	"gram.in" */
{ ioclause(yypt[-1].yyv.ival, IOSTDERR); } break;
case 278:
/* #line	1191	"gram.in" */
{ yyval.ival = iocname(); } break;
case 279:
/* #line	1195	"gram.in" */
{ iostmt = IOREAD; } break;
case 280:
/* #line	1199	"gram.in" */
{ iostmt = IOWRITE; } break;
case 281:
/* #line	1203	"gram.in" */
{
		iostmt = IOWRITE;
		ioclause(IOSUNIT, ENULL);
		ioclause(IOSFMT, yypt[-1].yyv.expval);
		endioctl();
		} break;
case 282:
/* #line	1210	"gram.in" */
{
		iostmt = IOWRITE;
		ioclause(IOSUNIT, ENULL);
		ioclause(IOSFMT, ENULL);
		endioctl();
		} break;
case 283:
/* #line	1219	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.tagval, CHNULL); } break;
case 284:
/* #line	1221	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.tagval, yypt[-2].yyv.chval); } break;
case 285:
/* #line	1225	"gram.in" */
{ yyval.tagval = (tagptr) yypt[-0].yyv.expval; } break;
case 286:
/* #line	1227	"gram.in" */
{ yyval.tagval = (tagptr) mkiodo(yypt[-1].yyv.chval,revchain(yypt[-3].yyv.chval)); } break;
case 287:
/* #line	1231	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, CHNULL); } break;
case 288:
/* #line	1233	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.tagval, CHNULL); } break;
case 290:
/* #line	1238	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, mkchain((char *)yypt[-2].yyv.expval, CHNULL) ); } break;
case 291:
/* #line	1240	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.tagval, mkchain((char *)yypt[-2].yyv.expval, CHNULL) ); } break;
case 292:
/* #line	1242	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, mkchain((char *)yypt[-2].yyv.tagval, CHNULL) ); } break;
case 293:
/* #line	1244	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.tagval, mkchain((char *)yypt[-2].yyv.tagval, CHNULL) ); } break;
case 294:
/* #line	1246	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.expval, yypt[-2].yyv.chval); } break;
case 295:
/* #line	1248	"gram.in" */
{ yyval.chval = mkchain((char *)yypt[-0].yyv.tagval, yypt[-2].yyv.chval); } break;
case 296:
/* #line	1252	"gram.in" */
{ yyval.tagval = (tagptr) yypt[-0].yyv.expval; } break;
case 297:
/* #line	1254	"gram.in" */
{ yyval.tagval = (tagptr) yypt[-1].yyv.expval; } break;
case 298:
/* #line	1256	"gram.in" */
{ yyval.tagval = (tagptr) mkiodo(yypt[-1].yyv.chval, mkchain((char *)yypt[-3].yyv.expval, CHNULL) ); } break;
case 299:
/* #line	1258	"gram.in" */
{ yyval.tagval = (tagptr) mkiodo(yypt[-1].yyv.chval, mkchain((char *)yypt[-3].yyv.tagval, CHNULL) ); } break;
case 300:
/* #line	1260	"gram.in" */
{ yyval.tagval = (tagptr) mkiodo(yypt[-1].yyv.chval, revchain(yypt[-3].yyv.chval)); } break;
case 301:
/* #line	1264	"gram.in" */
{ startioctl(); } break;
	}
	goto yystack;  /* stack new state and value */
}
