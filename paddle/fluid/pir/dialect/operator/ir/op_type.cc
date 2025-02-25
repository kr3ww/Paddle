// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/fluid/pir/dialect/operator/ir/op_type.h"

namespace paddle {
namespace dialect {
const pir::Type& SelectedRowsType::dtype() const { return storage()->dtype_; }

const phi::DDim& SelectedRowsType::dims() const { return storage()->dims_; }

const phi::DataLayout& SelectedRowsType::data_layout() const {
  return storage()->layout_;
}

const phi::LoD& SelectedRowsType::lod() const { return storage()->lod_; }

const size_t& SelectedRowsType::offset() const { return storage()->offset_; }

bool SelectedRowsType::classof(Type type) {
  if (type) {
    if (type.type_id() == type_id()) return true;
    if (auto wrap_type = type.dyn_cast<pir::WrapTypeInterface>()) {
      return classof(wrap_type.prim_type());
    }
  }
  return false;
}

SelectedRowsType SelectedRowsType::dyn_cast_impl(Type type) {
  if (type) {
    if (type.type_id() == type_id()) return SelectedRowsType(type.storage());
    if (auto wrap_type = type.dyn_cast<pir::WrapTypeInterface>()) {
      return dyn_cast_impl(wrap_type.prim_type());
    }
  }
  return nullptr;
}

const pir::Type& DenseTensorArrayType::dtype() const {
  return storage()->dtype_;
}
const phi::DDim& DenseTensorArrayType::dims() const { return storage()->dims_; }

const phi::DataLayout& DenseTensorArrayType::data_layout() const {
  return storage()->layout_;
}

bool DenseTensorArrayType::classof(Type type) {
  if (type) {
    if (type.type_id() == type_id()) return true;
    if (auto wrap_type = type.dyn_cast<pir::WrapTypeInterface>()) {
      return classof(wrap_type.prim_type());
    }
  }
  return false;
}

DenseTensorArrayType DenseTensorArrayType::dyn_cast_impl(Type type) {
  if (type) {
    if (type.type_id() == type_id())
      return DenseTensorArrayType(type.storage());
    if (auto wrap_type = type.dyn_cast<pir::WrapTypeInterface>()) {
      return dyn_cast_impl(wrap_type.prim_type());
    }
  }
  return nullptr;
}

}  // namespace dialect
}  // namespace paddle

IR_DEFINE_EXPLICIT_TYPE_ID(paddle::dialect::SelectedRowsType)
IR_DEFINE_EXPLICIT_TYPE_ID(paddle::dialect::DenseTensorArrayType)
