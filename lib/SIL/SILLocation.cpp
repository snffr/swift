//===--- SILLocation.cpp - Location information for SIL nodes -------------===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#include "swift/SIL/SILLocation.h"
#include "swift/AST/Decl.h"
#include "swift/AST/Expr.h"
#include "swift/AST/Pattern.h"
#include "swift/AST/Stmt.h"
using namespace swift;

SourceLoc SILLocation::getSourceLoc() const {
  if (ASTNode.isNull())
    return SourceLoc();
  if (auto decl = ASTNode.dyn_cast<Decl*>())
    return decl->getLoc();
  if (auto expr = ASTNode.dyn_cast<Expr*>())
    return expr->getLoc();
  if (auto stmt = ASTNode.dyn_cast<Stmt*>())
    return stmt->getStartLoc();
  if (auto patt = ASTNode.dyn_cast<Pattern*>())
    return patt->getStartLoc();
  llvm_unreachable("impossible SILLocation");
}

SourceLoc SILLocation::getStartSourceLoc() const {
  if (ASTNode.isNull())
    return SourceLoc();
  if (auto decl = ASTNode.dyn_cast<Decl*>())
    return decl->getStartLoc();
  if (auto expr = ASTNode.dyn_cast<Expr*>())
    return expr->getStartLoc();
  if (auto stmt = ASTNode.dyn_cast<Stmt*>())
    return stmt->getStartLoc();
  if (auto patt = ASTNode.dyn_cast<Pattern*>())
    return patt->getStartLoc();
  llvm_unreachable("impossible SILLocation");
}

SourceLoc SILLocation::getEndSourceLoc() const {
  if (ASTNode.isNull())
    return SourceLoc();
  if (auto decl = ASTNode.dyn_cast<Decl*>())
    return decl->getEndLoc();
  if (auto expr = ASTNode.dyn_cast<Expr*>())
    return expr->getEndLoc();
  if (auto stmt = ASTNode.dyn_cast<Stmt*>())
    return stmt->getEndLoc();
  if (auto patt = ASTNode.dyn_cast<Pattern*>())
    return patt->getEndLoc();
  llvm_unreachable("impossible SILLocation");
}
