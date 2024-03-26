type TextEditor struct {
	before []byte
	after  []byte
}

func Constructor() TextEditor {
	return TextEditor{}
}

func (this *TextEditor) AddText(text string) {
	this.before = append(this.before, text...)
}

func (this *TextEditor) DeleteText(k int) int {
	actualDelete := min(k, len(this.before))
	this.before = this.before[:len(this.before)-actualDelete]
	return actualDelete
}

func (this *TextEditor) CursorLeft(k int) string {
	chunkStart := max(len(this.before)-k, 0)
	chunk := this.before[chunkStart:]
	this.before = this.before[:chunkStart]
	this.after = slices.Insert(this.after, 0, chunk...)
	left := max(0, len(this.before)-10)
	return string(this.before[left:])
}

func (this *TextEditor) CursorRight(k int) string {
	chunkEnd := min(k, len(this.after))
	chunk := this.after[:chunkEnd]
	this.after = this.after[chunkEnd:]
	this.before = append(this.before, chunk...)
	left := max(0, len(this.before)-10)
	return string(this.before[left:])
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddText(text);
 * param_2 := obj.DeleteText(k);
 * param_3 := obj.CursorLeft(k);
 * param_4 := obj.CursorRight(k);
 */