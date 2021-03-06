/**
 * Copyright (c) 2017-present, Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */
#include "utils.h"

namespace facebook { namespace logdevice { namespace configuration {
namespace nodes {

bool shouldIncludeInNodesetSelection(const NodesConfiguration& nodes_config,
                                     ShardID shard) {
  // if `shard' is in membership then it must have an attribute
  // defined, thus direct deference is used
  return nodes_config.getStorageMembership()->canWriteToShard(shard) &&
      !nodes_config.getNodeStorageAttribute(shard.node())
           ->exclude_from_nodesets;
}

}}}} // namespace facebook::logdevice::configuration::nodes
