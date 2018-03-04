// Copyright Isara Technologies 2018

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Geometry2D.generated.h"

/**
 * 
 */
UCLASS()
class UGeometry2D : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/**
	 * Checks if the intervals [X1, X2] and [Y1, Y2] are overlapping. The parameters must be in the good order, i.e. X1 <= X2 and Y1 <= Y2.
	 */
	UFUNCTION(BlueprintCallable, Meta = (Category = "Geometry|Intersections"))
		static bool IntervalIntersection(float X1, float X2, float Y1, float Y2);

	/**
	 * Checks if two lines are intersecting.
	 */
	UFUNCTION(BlueprintCallable, Meta = (Category = "Geometry|Intersections"))
		static bool LineLineIntersection(const FVector2D& P1, const FVector2D& P2, const FVector2D& Q1, const FVector2D& Q2, FVector2D& Intersection);

	/**
	 * Checks if two segments are intersecting. If so Intersection is set to the intersection point.
	 * If the segments are overlapping, Intersection is set to the middle of the overlapping area and the function returns <code>true</code>
	 */
	UFUNCTION(BlueprintCallable, Meta=(Category="Geometry|Intersections"))
		static bool SegmentSegmentIntersection(const FVector2D& P1, const FVector2D& P2, const FVector2D& Q1, const FVector2D& Q2, FVector2D& Intersection);

	/**
	 * Checks if the segment [P1, P2] is intersecting the box, returns all intersections in Intersection
	 */
	UFUNCTION(BlueprintCallable, Meta = (Category = "Geometry|Intersections"))
		static bool BoxSegmentIntersection(const FBox2D& Box, const FVector2D& P1, const FVector2D& P2, TArray<FVector2D>& Intersection);
	
};
