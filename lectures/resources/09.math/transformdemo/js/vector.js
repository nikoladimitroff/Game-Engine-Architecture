
var Vector2 = function (x, y) {
    x = x || 0;
    y = y || 0;
    this.x = x;
    this.y = y;
}

Vector2.prototype.copy = function () {
    return new Vector2(this.x, this.y);
}

Vector2.prototype.dot = function (other) {
    return this.x * other.x + this.y * other.y;
}

Vector2.prototype.angleTo = function (other) {
    var n1 = this.copy(),
        n2 = other.copy();
    n1.normalize();
    n2.normalize();
    var cos = n1.dot(n2);
    var sin = ((n2.x + n2.y) - (n1.x + n1.y) * cos) / (n1.x - n1.y);
    var angle = Math.acos(cos);

    if (sin <= 0)
        angle = -angle;

    angle += Math.PI / 2
    return angle;
}

Vector2.prototype.distTo = function (other) {
    return Math.sqrt((this.x - other.x) * (this.x - other.x) +
                     (this.y - other.y) * (this.y - other.y))
};

Vector2.prototype.distToSquared = function (other) {
    return (this.x - other.x) * (this.x - other.x) +
           (this.y - other.y) * (this.y - other.y);
};

Vector2.prototype.len = function() {
    return Math.sqrt(this.x * this.x + this.y * this.y)
};

Vector2.prototype.normalize = function() {
    var len = this.len();
    this.x /= len;
    this.y /= len;
}

Vector2.prototype.sub = function (other) {
    return new Vector2(this.x - other.x, this.y - other.y);
}

Vector2.prototype.negate = function () {
    return new Vector2(-this.x, -this.y);
}

Vector2.prototype.add = function (other) {
    if (typeof other == "number") {
        return new Vector2(this.x + other, this.y + other);
    }
    return new Vector2(this.x + other.x, this.y + other.y);
}

Vector2.prototype.scale = function(scalar) {
    this.x *= scalar;
    this.y *= scalar;
}

Vector2.prototype.scaled = function(scalar) {
    return new Vector2(this.x * scalar, this.y * scalar);
}

Vector2.prototype.rotated = function(angle) {
    return new Vector2(
        this.x * Math.cos(angle) - this.y * Math.sin(angle),
        this.x * Math.sin(angle) + this.y * Math.cos(angle),
    );
}

Vector2.prototype.truncate = function (limit) {
    var len = this.len();
    if (len > limit) {
        this.scale(limit / len);
    }
}

Vector2.prototype.componentProduct = function (other) {
    return new Vector2(this.x * other.x, this.y * other.y);
};

Vector2.prototype.maxComponent = function () {
    return Math.max(this.x, this.y);
};

Vector2.prototype.minComponent = function () {
    return Math.min(this.x, this.y);
}

Vector2.prototype.reciproc = function () {
    return new Vector2(1 / this.x, 1 / this.y);
};

Vector2.prototype.lte = function (other) {
    return this.x <= other.x && this.y <= other.y;
}

Vector2.internal = {};
Vector2.internal.isValueInBetween = function (value, min, max) {
    return value >= min && value <= max;
}

Vector2.prototype.isInBetween = function (vec1, vec2) {
    return Vector2.internal.isValueInBetween(this.x, vec1.x, vec2.x) &&
        Vector2.internal.isValueInBetween(this.y, vec1.y, vec2.y);
}

Vector2.zero = new Vector2(0, 0);
Vector2.right = new Vector2(1, 0);
Vector2.left = new Vector2(-1, 0);
Vector2.up = new Vector2(0, 1);
Vector2.unit = new Vector2(1, 1);