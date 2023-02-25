<h2><a href="https://leetcode.com/problems/check-if-a-string-can-break-another-string/">1433. Check If a String Can Break Another String</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given two strings: <code style="user-select: auto;">s1</code> and <code style="user-select: auto;">s2</code> with the same&nbsp;size, check if some&nbsp;permutation of string <code style="user-select: auto;">s1</code> can break&nbsp;some&nbsp;permutation of string <code style="user-select: auto;">s2</code> or vice-versa. In other words <code style="user-select: auto;">s2</code> can break <code style="user-select: auto;">s1</code>&nbsp;or vice-versa.</p>

<p style="user-select: auto;">A string <code style="user-select: auto;">x</code>&nbsp;can break&nbsp;string <code style="user-select: auto;">y</code>&nbsp;(both of size <code style="user-select: auto;">n</code>) if <code style="user-select: auto;">x[i] &gt;= y[i]</code>&nbsp;(in alphabetical order)&nbsp;for all <code style="user-select: auto;">i</code>&nbsp;between <code style="user-select: auto;">0</code> and <code style="user-select: auto;">n-1</code>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s1 = "abc", s2 = "xya"
<strong style="user-select: auto;">Output:</strong> true
<strong style="user-select: auto;">Explanation:</strong> "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s1 = "abe", s2 = "acd"
<strong style="user-select: auto;">Output:</strong> false 
<strong style="user-select: auto;">Explanation:</strong> All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s1 = "leetcodee", s2 = "interview"
<strong style="user-select: auto;">Output:</strong> true
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">s1.length == n</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">s2.length == n</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 10^5</code></li>
	<li style="user-select: auto;">All strings consist of lowercase English letters.</li>
</ul>
</div>