// Copyright Isara Technologies 2018

#include "Geometry2D.h"

static bool IsNull(float A, float Epsilon = 1.0e-4f);
static bool IsNotNull(float A, float Epsilon = 1.0e-4f);
static bool BetweenInc(float V, float L, float U);

bool UGeometry2D::IntervalIntersection(float X1, float X2, float Y1, float Y2)
{
	return X1 <= Y2 && Y1 <= X2;
}

bool UGeometry2D::LineLineIntersection(const FVector2D& P1, const FVector2D& P2, const FVector2D& Q1, const FVector2D& Q2, FVector2D& Intersection)
{
	float S1X, S1Y, S2X, S2Y;
	S1X = P2.X - P1.X;     S1Y = P2.Y - P1.Y;
	S2X = Q2.X - Q1.X;     S2Y = Q2.Y - Q1.Y;

	float s, t;
	s = (-S1Y * (P1.X - Q1.X) + S1X * (P1.Y - Q1.Y)) / (-S2X * S1Y + S1X * S2Y);
	t = (S2X * (P1.Y - Q1.Y) - S2Y * (P1.X - Q1.X)) / (-S2X * S1Y + S1X * S2Y);

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		// Collision detected
		Intersection.X = P1.X + (t * S1X);
		Intersection.Y = P1.Y + (t * S1Y);
		return true;
	}

	return false; // No collision
}

bool UGeometry2D::SegmentSegmentIntersection(const FVector2D& P1, const FVector2D& P2, const FVector2D& Q1, const FVector2D& Q2, FVector2D& Intersection)
{
	FVector2D R = P2 - P1;
	FVector2D S = Q2 - Q1;

	float T = FVector2D::CrossProduct(Q1 - P1, S / (R ^ S));
	float U = FVector2D::CrossProduct(Q1 - P1, R / (R ^ S));

	if (IsNull(FVector2D::CrossProduct(R, S)) && IsNull(FVector2D::CrossProduct(Q1 - P1, R)))
	{
		float T0 = FVector2D::DotProduct(Q1 - P1,  R / FVector2D::DotProduct(R, R));
		float T1 = T0 + FVector2D::DotProduct(S, R / FVector2D::DotProduct(R, R));

		if (FVector2D::DotProduct(S, R) < 0)
		{
			if (IntervalIntersection(T1, T0, 0, 1))
			{
				if (T1 < 0 && T0 > 1)
					Intersection = P1 + 0.5f * R;
				else if (T1 > 0 && T0 < 1)
					Intersection = 0.5f * (P1 + T1 * R) + 0.5f * (P1 + T0 * R);
				else if (T1 < 0 && T0 < 1)
					Intersection = 0.5f * P1 + 0.5f * (P1 + T0 * R);
				else
					Intersection = 0.5f * P2 + 0.5f * (P1 + T1 * R);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (IntervalIntersection(T0, T1, 0, 1))
			{
				if (T0 < 0 && T1 > 1)
					Intersection = P1 + 0.5f * R;
				else if (T0 > 0 && T1 < 1)
					Intersection = 0.5f * (P1 + T0 * R) + 0.5f * (P1 + T1 * R);
				else if (T0 < 0 && T1 < 1)
					Intersection = 0.5f * P1 + 0.5f * (P1 + T1 * R);
				else
					Intersection = 0.5f * P2 + 0.5f * (P1 + T0 * R);
				return true;
			}
			else
			{
				return false;
			}
		}
		
	} 
	if (IsNull(FVector2D::CrossProduct(R, S)) && IsNotNull(FVector2D::CrossProduct(Q1 - P1, R))) {
		return false;
	}
	if (IsNotNull(FVector2D::CrossProduct(R, S)) && BetweenInc(T, 0, 1) && BetweenInc(U, 0, 1)) {
		Intersection = P1 + T * R;
		return true;
	}
	return false;
}

bool UGeometry2D::BoxSegmentIntersection(const FBox2D& Box, const FVector2D& P1, const FVector2D& P2, TArray<FVector2D>& Intersections)
{
	FVector2D Size = Box.GetSize();
	FVector2D I;

	bool Intersects = false;

	// Left edge
	if (SegmentSegmentIntersection(P1, P2, Box.Min, Box.Min + FVector2D(0, Size.Y), I)) {
		Intersections.Add(I);
		Intersects = true;
	}
	// Top edge
	if (SegmentSegmentIntersection(P1, P2, Box.Min, Box.Min + FVector2D(Size.X, 0), I)) {
		Intersections.Add(I);
		Intersects = true;
	}
	// Right edge
	if (SegmentSegmentIntersection(P1, P2, Box.Min + FVector2D(Size.X, 0), Box.Max, I)) {
		Intersections.Add(I);
		Intersects = true;
	}
	// Bottom edge
	if (SegmentSegmentIntersection(P1, P2, Box.Min + FVector2D(0, Size.Y), Box.Max, I)) {
		Intersections.Add(I);
		Intersects = true;
	}

	return Intersects;
}

static bool IsNull(float A, float Epsilon)
{
	return FMath::Abs(A) < Epsilon;
}

static bool IsNotNull(float A, float Epsilon)
{
	return !IsNull(A, Epsilon);
}

static bool BetweenInc(float V, float L, float U)
{
	return V >= L && V <= U;
}