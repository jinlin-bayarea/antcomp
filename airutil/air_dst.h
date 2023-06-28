#ifndef AIR_DST_H
#define AIR_DST_H


#include "dwarf_DST.h"
#include "dwarf_DST_mem.h"
// workaround for define inline/WEAK in defs.h
#undef inline
#undef WEAK

#include "open64decl.h"

// stdc++
//#include "c2w_map.h"
#include <string>

namespace acc {

class WhirlBuilder;

class WhirlDstBuilder {
private:
  WhirlBuilder *_builder;
/*
  USRCPOS _cur_loc;
  
  STR_IDX_MAP  _dir_map;
  STR_IDX_MAP  _file_map;
  TYPE_DST_MAP _type_map;
  ST_DST_MAP  _sym_map;
*/
public:
  WhirlDstBuilder(WhirlBuilder *builder);
  
  ~WhirlDstBuilder();
  
  void Initialize();

  DST_INFO_IDX CreateDstForCompileUnit();
  DST_INFO_IDX CreateDstForFunc(ST_IDX st, TY_IDX rtype);
  DST_language GetLanguage() const;
  const char *GetProducer() const;
  DST_identifier_case GetIdentifierCase() const;
};

}
#endif 
