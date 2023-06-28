#include "air_scope.h"
#include "air_builder.h"

// open64 includes
#include "open64inc.h"

namespace acc {
WhirlScopeManager::WhirlScopeManager(WhirlBuilder *builder)
  : _builder(builder), _switch_to_global(false) {
}

WhirlScopeManager::~WhirlScopeManager() {
}

void
WhirlScopeManager::Initialize() {
  Is_True(_scopes.size() == 0,
          ("_scopes mismatch"));
  _scopes.push_back(Scope(GLOBAL_SYMTAB));
  DST_INFO_IDX dst_idx = _builder->DstBuilder().CreateDstForCompileUnit();
  _scopes.back()._dst = dst_idx;
}
} // namespace acc

