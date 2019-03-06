#ifndef SSD_CAFFE_DATA_LAYER_HPP_
#define SSD_CAFFE_DATA_LAYER_HPP_

#ifdef SSD_CAFFE

#include <string>
#include <vector>
#include "caffe/blob.hpp"
#include "caffe/ssd_data_reader.hpp"
#include "caffe/ssd_data_transformer.hpp"
#include "caffe/internal_thread.hpp"
#include "caffe/layer.hpp"
#include "caffe/layers/base_data_layer.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/db.hpp"

namespace caffe {

template <typename Dtype>
class AnnotatedDataLayer : public BasePrefetchingDataLayer<Dtype> {
 public:
  explicit AnnotatedDataLayer(const LayerParameter& param);
  virtual ~AnnotatedDataLayer();
  virtual void DataLayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  // AnnotatedDataLayer uses DataReader instead for sharing for parallelism
  virtual inline bool ShareInParallel() const { return false; }
  virtual inline const char* type() const { return "AnnotatedData"; }
  virtual inline int ExactNumBottomBlobs() const { return 0; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  virtual void load_batch(Batch<Dtype>* batch);

  DataReader<AnnotatedDatum> reader_;
  bool has_anno_type_;
  AnnotatedDatum_AnnotationType anno_type_;
  vector<BatchSampler> batch_samplers_;
  string label_map_file_;

  shared_ptr<SSDDataTransformer<Dtype> > data_transformer_;
};

}  // namespace caffe

#endif // SSD_CAFFE

#endif  // SSD_CAFFE_DATA_LAYER_HPP_
