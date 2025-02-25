#   Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from paddle.base.libpaddle.pir import (  # noqa: F401
    Block,
    CloneOptions,
    IrMapping,
    Operation,
    OpOperand,
    PassManager,
    Program,
    Type,
    Value,
    check_unregistered_ops,
    create_shaped_type,
    fake_value,
    get_current_insertion_point,
    is_fake_value,
    parse_program,
    register_dist_dialect,
    register_paddle_dialect,
    reset_insertion_point_to_end,
    reset_insertion_point_to_start,
    set_insertion_point,
    set_insertion_point_to_block_end,
    translate_to_pir,
    translate_to_pir_with_param_map,
)

from . import core  # noqa: F401
from .math_op_patch import monkey_patch_value  # noqa: F401
from .program_patch import monkey_patch_program  # noqa: F401

__all__ = []
