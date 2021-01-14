#include "Cond.h"

namespace V3DLib {
namespace {

/**
 * Generic 'Float' comparison
 */
BoolExpr mkFloatCmp(FloatExpr a, CmpOp op, FloatExpr b) {
	return BoolExpr(mkCmp(a.expr(), op, b.expr()));
}


/**
 * Generic 'Int' comparison
 */
BoolExpr mkIntCmp(IntExpr a, CmpOp op, IntExpr b) {
	return BoolExpr(mkCmp(a.expr(), op, b.expr()));
}

}  // anon namespace


BExpr::Ptr mkCmp(Expr::Ptr lhs, CmpOp op, Expr::Ptr rhs) {
  return BExpr::Ptr(new BExpr(lhs, op, rhs));
}


// ============================================================================
// Specific 'Int' comparisons
// ============================================================================

BoolExpr operator==(IntExpr a, IntExpr b) { return mkIntCmp(a, CmpOp(EQ, INT32), b); }
BoolExpr operator!=(IntExpr a, IntExpr b) { return mkIntCmp(a, CmpOp(NEQ, INT32), b); }
BoolExpr operator<(IntExpr a, IntExpr b)  { return mkIntCmp(a, CmpOp(LT, INT32), b); }
BoolExpr operator<=(IntExpr a, IntExpr b) { return mkIntCmp(a, CmpOp(LE, INT32), b); }
BoolExpr operator>(IntExpr a, IntExpr b)  { return mkIntCmp(a, CmpOp(GT, INT32), b); }
BoolExpr operator>=(IntExpr a, IntExpr b) { return mkIntCmp(a, CmpOp(GE, INT32), b); }



// ============================================================================
// Specific 'Float' comparisons
// ============================================================================

BoolExpr operator==(FloatExpr a, FloatExpr b) { return mkFloatCmp(a, CmpOp(EQ, FLOAT), b); }
BoolExpr operator!=(FloatExpr a, FloatExpr b) { return mkFloatCmp(a, CmpOp(NEQ, FLOAT), b); }
BoolExpr operator<(FloatExpr a, FloatExpr b)  { return mkFloatCmp(a, CmpOp(LT, FLOAT), b); }
BoolExpr operator<=(FloatExpr a, FloatExpr b) { return mkFloatCmp(a, CmpOp(LE, FLOAT), b); }
BoolExpr operator>(FloatExpr a, FloatExpr b)  { return mkFloatCmp(a, CmpOp(GT, FLOAT), b); }
BoolExpr operator>=(FloatExpr a, FloatExpr b) { return mkFloatCmp(a, CmpOp(GE, FLOAT), b); }


// ============================================================================
// Boolean operators
// ============================================================================

BoolExpr operator!(BoolExpr a)              { return BoolExpr(a.bexpr()->Not()); }
BoolExpr operator&&(BoolExpr a, BoolExpr b) { return BoolExpr(a.bexpr()->And(b.bexpr())); }
BoolExpr operator||(BoolExpr a, BoolExpr b) { return BoolExpr(a.bexpr()->Or(b.bexpr())); }

Cond any(BoolExpr a) { return Cond(mkAny(a.bexpr())); }
Cond all(BoolExpr a) { return Cond(mkAll(a.bexpr())); }

}  // namespace V3DLib
