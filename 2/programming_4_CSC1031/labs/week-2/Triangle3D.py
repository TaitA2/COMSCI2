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


class Triangle3D:
    def __init__(self, dot1, dot2, dot3):
        self.dot1 = dot1
        self.dot2 = dot2
        self.dot3 = dot3

    def calculate_perimeter(self):
        return sum(self.__get_edges__())

    def calculate_area(self):
        edges = self.__get_edges__()
        s = sum(edges) / 2
        area = (s * (s - edges[0]) * (s - edges[1]) * (s - edges[2])) ** 0.5

        return area

    def __get_edges__(self):
        edge1 = self.dot1.distance_to(self.dot2)
        edge2 = self.dot2.distance_to(self.dot3)
        edge3 = self.dot3.distance_to(self.dot1)
        return [edge1, edge2, edge3]
