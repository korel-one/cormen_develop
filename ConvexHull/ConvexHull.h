#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
struct Point
{
  Point(const T& i_x, const T i_y)
    : x(i_x), y(i_y)
  {
  }

  Point operator- (const Point& i_p) const
  {
  return Point(x - i_p.x, y - i_p.y);
  }

  T x, y;
};
typedef Point<int> PointI;
typedef std::vector<PointI> PointsInt;

template <typename TPoint>
const TPoint& left_most(std::vector<TPoint>& o_points)
{
  std::sort(o_points.begin(), o_points.end(), [](const TPoint& p1, const TPoint& p2){
    return p1.x < p2.x;
  });

  return o_points.front();
}

template <typename TVector>
int pseudo_scalar_product(const TVector& v1, const TVector& v2)
{
   return v1.x*v2.y - v1.y*v2.x;
}

template <typename TPoint>
void sort_by_angle(const TPoint& i_origin, std::vector<TPoint>& o_points)
{
  std::sort(o_points.begin(), o_points.end(), [&i_origin] (const TPoint& i_p1, const TPoint& i_p2) {
    TPoint curr1 = i_p1 - i_origin;
    TPoint curr2 = i_p2 - i_origin;

    return pseudo_scalar_product(curr1, curr2) > 0;
  });
}

template <typename TPoints>
void print(const TPoints& points)
{
  std::for_each(std::begin(points), std::end(points), [](const typename TPoints::value_type& point) {
    std::cout<< point.x <<" " <<point.y<<"\n";
  });
}

template <typename TPoint>
bool inner_angle(const TPoint& origin,
                 const TPoint& p_left, const TPoint& p_center, const TPoint& p_right)
{
  TPoint u(p_center.x - origin.x, p_center.y - origin.y);
  TPoint v1(p_left.x - origin.x, p_left.y - origin.y);
  TPoint v2(p_right.x - origin.x, p_right.y - origin.y);

  //check whether (origin, center) crosses (left, right)
  int res1 = pseudo_scalar_product(u, v1)*pseudo_scalar_product(u, v2);

  TPoint p(p_left.x - p_right.x, p_left.y - p_right.y);
  TPoint q1(p_center.x - p_right.x, p_center.y - p_right.y);
  TPoint q2(origin.x - p_right.x, origin.y - p_right.y);

  //check whether (right, left) crosses (origin, center)
  int res2 = pseudo_scalar_product(p, q1)*pseudo_scalar_product(p, q2);

  //segments cross and have a common point
  return res1 < 0 && res2 < 0;
}

template <typename TPoints>
class ConvexHullCalculator
{
private:
	typedef typename TPoints::value_type TPoint;

public:
	ConvexHullCalculator(const TPoint& origin, const TPoints& sorted_points)
    {
		unsigned int i = 0;//handled points
		calculate(i, sorted_points, origin);
    }

	void calculate(unsigned int i, const TPoints& sorted_points, const TPoint& origin)
	{
		if (sorted_points.empty() || i == sorted_points.size()-1)
			return;

		if(m_convex_hull.size() < 2 ||
				inner_angle(origin, sorted_points.at(i)
						, *(m_convex_hull.end() - 1)
						, *(m_convex_hull.end() - 2)))
		{
			m_convex_hull.push_back(sorted_points.at(i));
			calculate(++i, sorted_points, origin);
		}
		else
		{
			m_convex_hull.erase(m_convex_hull.end()-1);
			calculate(i, sorted_points, origin);
		}
	}

	void print() const
	{
		::print(m_convex_hull);
	}

private:
	TPoints m_convex_hull;
};

//-----------------------------------------------------------------------------
template <typename TPoint, size_t N>
void get_convex_hull(TPoint (&points)[N])
{
  PointsInt points_vec(std::begin(points), std::end(points));

  PointI leftMost(left_most(points_vec));
  sort_by_angle(leftMost, points_vec);

  //print(points_vec);

  ConvexHullCalculator<PointsInt> covexHullCalculator(leftMost, points_vec);
  covexHullCalculator.print();
}
