// caffe.hpp is the header file that you need to include in your code. It wraps
// all the internal caffe header files into one for simpler inclusion.

#ifndef SSD_CAFFE_CAFFE_HPP_
#define SSD_CAFFE_CAFFE_HPP_

#include "caffe/blob.hpp"
#include "caffe/ssd_common.hpp"
#include "caffe/filler.hpp"
#include "caffe/layer.hpp"
#include "caffe/layer_factory.hpp"
#include "caffe/ssd_net.hpp"
#include "caffe/ssd_parallel.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/ssd_solver.hpp"
#include "caffe/solver_factory.hpp"
#include "caffe/util/benchmark.hpp"
#include "caffe/util/io.hpp"
#include "caffe/util/upgrade_proto.hpp"

#endif  // SSD_CAFFE_CAFFE_HPP_
