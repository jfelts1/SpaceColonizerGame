/*
James Felts 2015
*/
#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
namespace Utils
{
	struct Vector2D
	{
		friend inline std::ostream& operator<<(std::ostream& out, const Vector2D& vect)
		{
			out << "(" << vect.m_x << "," << vect.m_y << ")";
			return out;
		}

		constexpr Vector2D() = default;
		virtual ~Vector2D() noexcept{}
		float getX()const noexcept{ return m_x; }
		float getY()const noexcept{ return m_y; }
		void setX(float x) noexcept
		{
			m_x = x;
			updateMagnitude();
		}
		void setY(float y) noexcept
		{
			m_y = y;
			updateMagnitude();
		}
		float getMagnitude() const noexcept{ return m_magnitude; }
		void truncate(const float maxSize) noexcept
		{
			if (m_magnitude > maxSize)
			{
				float ratio = maxSize / m_magnitude;
				m_y = m_y*ratio;
				m_x = m_x*ratio;
			}
		}

		Vector2D operator+(const Vector2D& rhs)const noexcept
		{
			Vector2D ret;
			ret.setX(this->getX() + rhs.getX());
			ret.setY(this->getY() + rhs.getY());
			return ret;
		}

		Vector2D& operator+=(const Vector2D& rhs)noexcept
		{
			setX(this->getX() + rhs.getX());
			setY(this->getY() + rhs.getY());
			return *this;
		}

		Vector2D operator-(const Vector2D& rhs)const noexcept
		{
			Vector2D ret;
			ret.setX(this->getX() - rhs.getX());
			ret.setY(this->getY() - rhs.getY());
			return ret;
		}

		Vector2D& operator-=(const Vector2D& rhs)noexcept
		{
			setX(this->getX() - rhs.getX());
			setY(this->getY() - rhs.getY());
			return *this;
		}

		float dotProduct(const Vector2D&rhs)const noexcept
		{
			return this->m_x*rhs.m_x + this->m_y*rhs.m_y;
		}

	private:
		float m_x = 0;
		float m_y = 0;
		float m_magnitude = 0;
		void updateMagnitude() noexcept
		{
			m_magnitude = sqrtf((m_x*m_x) + (m_y*m_y));
		}

	};
}
#endif

