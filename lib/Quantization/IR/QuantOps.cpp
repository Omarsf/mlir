//===- QuantOps.cpp - Quantization Type and Ops Implementation --*- C++ -*-===//
//
// Copyright 2019 The MLIR Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// =============================================================================

#include "mlir/Quantization/QuantOps.h"
#include "TypeDetail.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/Quantization/QuantTypes.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Twine.h"
#include "llvm/Support/MathExtras.h"

using namespace mlir;
using namespace mlir::quant;
using namespace mlir::quant::detail;

#define GET_OP_CLASSES
#include "mlir/Quantization/QuantOps.cpp.inc"

QuantizationDialect::QuantizationDialect(MLIRContext *context)
    : Dialect(/*name=*/"quant", context) {
  addTypes<UniformQuantizedType, UniformQuantizedPerAxisType>();
  addOperations<
#define GET_OP_LIST
#include "mlir/Quantization/QuantOps.cpp.inc"
      >();
}
