#include <jni.h>

#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>

extern "C" JNIEXPORT void JNICALL
Java_com_kkaefer_boostrtree_MainActivity_callJNI(JNIEnv *) {
  using Point = boost::geometry::model::point<double, 2, boost::geometry::cs::cartesian>;
  using RTree = boost::geometry::index::rtree<Point, boost::geometry::index::rstar<16, 4>>;

  RTree rtree;
  rtree.insert(Point(2, 3));
}
