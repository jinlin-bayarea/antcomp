#ifndef AIR_SCOPE_H
#define AIR_SCOPE_H

// forward open64 declarations
#include "dwarf_DST_mem.h"
// workaround for define inline/WEAK in defs.h
#undef inline
#undef WEAK

#include "open64decl.h"
#include "open64inc.h"

namespace acc {

class WhirlBuilder;

class WhirlScopeManager {
private:
  WhirlBuilder *_builder;

 class Scope {
    friend class WhirlScopeManager;

  private:
    UINT32 _level;                 // level of the scope, starts from GLOBAL_SYMTAB
    DST_INFO_IDX _dst;                   // dst for the scope
    //std::vector<LexicalBlockScope> _blocks;    // lexicalscopes in the function
    ST_IDX _this;                  // symbol of 'this' in current scope
    //ST_IDX_MAP         _st_map;                // symbols in the scope (include lexical blocks)   // 2018
  public:
    Scope(UINT32 level)
      : _level(level), _dst(DST_INVALID_IDX), _this(0) {
    }
  };

  std::vector<Scope> _scopes;
  bool _switch_to_global;


private:
//  DST_INFO_IDX CreateDst(const Scope &scope) const;

//  DST_INFO_IDX CreateDst(const LexicalBlockScope &scope) const;

public:
  WhirlScopeManager(WhirlBuilder *builder);

  ~WhirlScopeManager();

  void Initialize();
}; // WhirlScopeManager
} // namespace acc


#endif /* AIR_SCOPE_H */

