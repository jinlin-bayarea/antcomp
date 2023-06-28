#include "open64inc.h"
#include "erglob.h"
#include <unistd.h>

#include "air_builder.h"
BOOL TARGET_64BIT;
static Output_File *Irb_Output_File = NULL;
const char *_saved_error_phase;

namespace acc {
WhirlBuilder::WhirlBuilder()
  : _dst_builder(this), 
    _scope(this) {
}

WhirlBuilder::~WhirlBuilder() {
}

void
WhirlBuilder::Initialize(const char *infile) {
  TARGET_64BIT = TRUE;
  ABI_Name = "n64";
  MEM_Initialize();
  const char *const phase_name = "ONNX2Whirl Builder";
  Set_Error_Phase(phase_name);
  Set_Error_File(NULL);
  Set_Error_Line(ERROR_LINE_UNKNOWN);
  Src_File_Name = (char *) infile;
  Irb_File_Name = "/tmp/output";
  Preconfigure();
  Init_Controls_Tbl();
  Configure();
  Initialize_Symbol_Tables(TRUE);
  IR_reader_init();
  Irb_Output_File = Open_Output_Info("/tmp/out");
  _saved_error_phase = Get_Error_Phase();
  Set_Error_Phase(phase_name);
  _dst_builder.Initialize();
  _scope.Initialize();
}

}
