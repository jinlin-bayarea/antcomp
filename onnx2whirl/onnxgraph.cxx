// model resolving part of the toC Graph class
#include "onnxgraph.h"
#include "onnx.pb.h"
#include "options.h"

#include <iostream>


using namespace toWhirl;
using namespace acc;


ONNXGraph::ONNXGraph(
	onnx::ModelProto &onnx_model
	)
	:model(onnx_model)
{
	processGraph(onnx_model);
}

void ONNXGraph::processGraph(
	onnx::ModelProto &onnx_model
	)
{
	onnx::GraphProto onnx_graph = onnx_model.graph();
	Builder.Initialize("main_graph.c");
#if 0
	Node::onnx_ir_version = onnx_ir_version();
	// 0. add provided external initializers (from test bench
	LOG(DEBUG) << "Adding external (testsuite) tensors." <<std::endl;
	for( auto t : ext_inputs ) {
		LOG(DEBUG) << "  - " << t->name <<std::endl;
		tensors.push_back(t);
	}

	// 1. add initializers as resolved tensors
	// in case of quantization, make quantized copies here
	LOG(DEBUG) << "Adding initialized constant tensors from .onnx file." <<std::endl;
	for( auto i : onnx_graph.initializer() )
		addInitializedTensor( i );

	// 2. add graph inputs as resolved tensors
	// in case of quantization, convert all IO to INT8
	LOG(DEBUG) << "Marking graph input tensors as IO." <<std::endl;
	for ( auto i : onnx_graph.input() ) {
		Tensor *n = getIoTensor( i );
		addTensor( n );
	}

	// 3. Do the nodes
	LOG(DEBUG) << "Resolving nodes." <<std::endl;
	resolveGraphNodes(onnx_graph);

	// 4. Add the IO tag to those tensors the user wants back.
	LOG(DEBUG) << "Marking graph output tensors as IO." <<std::endl;
	for ( auto o : onnx_graph.output() ) {
		Tensor *n = getIoTensor( o );
		addTensor(n);
	}
#endif
}




