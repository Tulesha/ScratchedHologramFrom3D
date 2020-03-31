#pragma once

#include <AVector2D.hpp>

namespace Geometry2D {

    /**
     * @author github.com/Tulesha
     */
    class CPoint2D {
    private:
        double x = 0.0;
        double y = 0.0;

    public:
        /**
         * Base constructor
         */
        CPoint2D() = default;

        /**
         * Copy constructor Lvalue
         * @param cPoint2D Point in 2D
         */
        CPoint2D(const CPoint2D &point) noexcept;

        /**
         * Copy constructor Rvalue
         * @param cPoint2D Point in 2D
         */
        CPoint2D(CPoint2D &&point) noexcept;

        /**
         * Constructor with parameters of coordinates
         * @param x Coordinate X
         * @param y Coordinate Y
         */
        CPoint2D(double x, double y) noexcept;

        /**
         * Get coordinate x
         * @return Coordinate x
         */
        double getX() const noexcept;

        /**
         * Get coordinate y
         * @return Coordinate y
         */
        double getY() const noexcept;

        /**
         * Shift point by vector
         * @param vector Input vector in 2D
         */
        void move(const AVector2D &vector) noexcept;

        /**
         * Shift point by vector
         * @param vector Input vector in 2D
         * @return new CPoint2D
         */
        CPoint2D moveCopy(const AVector2D &vector) const noexcept;

        CPoint2D &operator=(const CPoint2D &vector);
    };
}
