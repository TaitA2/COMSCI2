class Dot3D:
    def __init__(self, x, y, z, label=None):
        self.x = x
        self.y = y
        self.z = z
        self.label = label

    def distance_to(self, other):
        return (
            (other.x - self.x) ** 2 + (other.y - self.y) ** 2 + (other.z - self.z) ** 2
        ) ** 0.5

    def add_vector(self, other):
        return Dot3D(
            self.x + other.x,
            self.y + other.y,
            self.z + other.z,
            self.label + "+" + other.label,
        )
