#ifndef ONNX2WHIRL_ONNXGRAPH_H
#define ONNX2WHIRL_ONNXGRAPH_H

#include "onnx.pb.h"
#include "air_builder.h"

namespace toWhirl {

class ONNXGraph {
public:
	ONNXGraph(
		onnx::ModelProto &onnx_model
	);


	void processGraph(
		onnx::ModelProto &onnx_model
	);

private:
	onnx::ModelProto &model;
	acc::WhirlBuilder Builder;	

};

}
#endif
