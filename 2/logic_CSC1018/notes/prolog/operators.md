# Operators
## Placement
* Multiple possible placements
  * Infix: a + b
  * Prefix: +(a, b)
  * Postfix: a b +
* Prolog internally uses **Prefix**
  * The operator is the *functor* of the relation
* Prolog supports infix and postfix notations as external representations

## Precedence
* `a + b * c`
* Could be read as:
  * `+(a, *(b, c))`
  * `*(+(a, b), c)`
* Correct reading depends on *precedence* and *type* of the operators.
* Prolog has special clauses called directives. The **op** directive has the syntax:
  * ` :- op(precedence, type, name).`
* The operator name is an atom and becomes the *functor* of the operator.
* The *precedence* is usually between 0 and 1200
  * Operators with *lower precedence* bind **more tightly** than operators with higher precedences.
* If an argument is in parenthesis or is an unstructured data object its precedence is 0
* If an argument is a structured data object then its precedence is the precedence of its principal functor

### Precedence Types
* The type of an operator can be:
  * Infix: xfx, xfy, yfx
  * prefix: fx, fy
  * postfix xf, yf
* **f** - the operator
* **x** - an argument whose precedence must be less than the precedence of the operator
* **y** - an argument whose precedence must be less than *or equal to* the precedence of the operator
  * **yfx** represents *left-to-right* evaluation

### Example
* a - b - c
* Should be interpreted as (a - b) - c
* Defined as:
  * `:- op(500, yfx, -)`
