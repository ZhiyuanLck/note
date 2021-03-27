# Re-Id

任务描述

Given a query person-of-interest, the goal of Re-ID is to determine whether this person has appeared in another place at a distinct time captured by a different camera, or even the same camera at a different time instant.

面临的困难

- the presence of different viewpoints
- varying low-image resolution
- illumination changes
- unconstrained poses
- occlusions
- hetorogeneous modalities
- complex camera environments
- background clutter
- unreliable bounding box generations

构建 Re-Id 系统基本步骤

1. Raw Data Collection
2. Bounding Box Generation
3. Training Data Annotation
4. Model Training
5. Pedestrian Retrieval

## 封闭世界 person Re-Id

假设

1. person appearances are captured by **single-modality visible cameras**, either by image or video
2. The persons are represented by **bounding boxes**, where most of the bounding box area belongs the same identity
3. The training has **enough annotated training data** for supervised discriminative Re-ID model learning
4. The annotations are generally **correct**
5. The query person must **appear in the gallery set**

### Feature Representation Learning

1. Global Feature, it extracts a global feature representation vector for each person image without additional annotation cues
2. Local Feature,  it aggregates part-level local features to formulate a combined representation for each person image
3. Auxiliary Feature,  it improves the feature representation learning using auxiliary information, e.g., attributes, GAN generated images
4. Video Feature, it learns video representation for video-based Re-ID using multiple image frames and temporal information

注意力机制

- Attention within the person image
- Attention across multiple person images

视频学习

Handling the noisy frames can greatly improve the video representation learning.

#### backbone

使用最广泛的 backbone: ResNet50

优化修改：

- 将最后一个卷积层的 stipe/size 改为1
- 最后一个池化层使用 adaptive average pooling
- 池化层后添加使用 batch normalization 的 bottleneck layer

前两条来自 Beyond part models: Person retrieval with refined part pooling

第三条来自 Svdnet for pedestrian retrieval

### Loss

- identity loss
- verification loss
- triplet loss
- OMI loss

### 训练手段

不平衡的数据集：identity sampling

平衡正负样本：adaptive sampling

- Sample Rate Learning
- curriculum sampling

### 评价标准

- CMC
- mAP
- FLOPs

### 19年比较好的网络

- Aware loss with angular regularization for person re-identification
- Discriminative feature learning with consistent attention regularization for person re- identification
- Second-order non-local attention networks for person re-identification
- Abd-net: Attentive but diverse person re-identification
