#ifndef BOOLEAN_MASK_OPS_H
#define BOOLEAN_MASK_OPS_H

#include "caffe2/core/context.h"
#include "caffe2/core/operator.h"
#include "caffe2/core/tensor.h"

namespace caffe2 {

template <class Context>
class BooleanMaskOp final : public Operator<Context> {
 public:
  USE_OPERATOR_CONTEXT_FUNCTIONS;
  BooleanMaskOp(const OperatorDef& operator_def, Workspace* ws)
      : Operator<Context>(operator_def, ws) {}

  bool RunOnDevice() override;
};

template <class Context>
class SequenceMaskOp final : public Operator<Context> {
 public:
  USE_OPERATOR_CONTEXT_FUNCTIONS;
  explicit SequenceMaskOp(const OperatorDef& operator_def, Workspace* ws)
      : Operator<Context>(operator_def, ws),
        axis_(OperatorBase::GetSingleArgument<int>("axis", 1)) {
    // Mode argument is required
    mode_ = GetArgument(operator_def, "mode").s();
  }

  bool RunOnDevice() override;

 private:
  int axis_;
  std::string mode_;
};

} // caffe2

#endif
