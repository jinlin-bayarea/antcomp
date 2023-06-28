#include "air_dst.h"
#include "air_builder.h"

// open64 header files
#include "open64inc.h"
#include "dwarf.h"
#include "dwarf_DST.h"
#include "dwarf_DST_producer.h"
#include "air_version.h"

// stdc++
#include <string>

namespace acc {

WhirlDstBuilder::WhirlDstBuilder(WhirlBuilder *builder)
  : _builder(builder) {
}

WhirlDstBuilder::~WhirlDstBuilder() {
}

void
WhirlDstBuilder::Initialize() {
  DST_Init(NULL, 0);
}

DST_INFO_IDX
WhirlDstBuilder::CreateDstForCompileUnit() {
  std::string dir;
  std::string file;
  //const FileEntry *fe = NULL;
  //GetFileInfo(fe, file, dir, NULL, NULL);
  return DST_mk_compile_unit(const_cast<char *>(file.c_str()),
                             const_cast<char *>(dir.c_str()),
                             const_cast<char *>(GetProducer()),
                             GetLanguage(),
                             GetIdentifierCase());
}

const char *
WhirlDstBuilder::GetProducer() const {
  return COMPILER_FULL_VERSION;
}

DST_language
WhirlDstBuilder::GetLanguage() const {
  return DW_LANG_C89;
}

DST_identifier_case
WhirlDstBuilder::GetIdentifierCase() const {
  return DW_ID_case_sensitive;
}

DST_INFO_IDX
WhirlDstBuilder::CreateDstForFunc(ST_IDX st, TY_IDX rtype) {
  USRCPOS spos;
  USRCPOS_clear(spos);
  DST_INFO_IDX type_dst = DST_INVALID_IDX;
  DST_INFO_IDX func_dst = DST_mk_subprogram(spos,
                                            const_cast<char *>(ST_name(st)),
                                            type_dst,
                                            DST_INVALID_IDX,
                                            st,
                                            DW_INL_not_inlined,
                                            DW_VIRTUALITY_none,
                                            0,                    // vtbl index
                                            false,                // is decl
                                            false,                // prototyped
                                            true,                 // artificial
                                            true);                // internal
  return func_dst;
}

}
