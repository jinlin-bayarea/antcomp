#ifndef AIR_BUILDER_H
#define AIR_BUILDER_H

#include "open64decl.h"
#include "air_dst.h"
#include "air_scope.h"

namespace acc {

class WhirlBuilder {
private:
  WhirlDstBuilder   _dst_builder;
  WhirlScopeManager _scope;	
public:
  WhirlBuilder();
  ~WhirlBuilder();
  void Initialize(const char *infile);
  WhirlDstBuilder &DstBuilder() { return _dst_builder; }
};

}

#endif /* AIR_BUILDER_H */
