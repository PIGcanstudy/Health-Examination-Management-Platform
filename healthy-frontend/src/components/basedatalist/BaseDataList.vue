<template>
  <div class="form">
    <div class="top">
      <div class="form-item">
        <label for="id" style="width: 70px">科室编码</label>
        <el-input id="id" placeholder="请输入科室编码" style="margin-left: 10px; width: 120px" />
      </div>
      <div class="form-item">
        <label for="name" style="width: 70px">科室名称</label>
        <el-input id="name" placeholder="请输入科室名称" style="margin-left: 10px; width: 120px"></el-input>
      </div>
      <div class="form-item">
        <label for="jp" style="width: 70px">科室简拼</label>
        <el-input id="jp" placeholder="请输入科室简拼" style="margin-left: 10px; width: 120px"></el-input>
      </div>
      <div class="form-item">
        <label style="width: 70px">检查类型</label>
        <el-select v-model="value" class="m-2" placeholder="请选择" style="margin-left: 10px; width: 120px">
          <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
        </el-select>
      </div>
      <div class="form-item">
        <el-row>
          <el-button type="primary">搜索</el-button>
          <el-button type="plain">重置</el-button>
        </el-row>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const value = ref('')

const options = [
  {
    value: '职业体检',
    label: '职业体检'
  },
  {
    value: '健康体检',
    label: '健康体检'
  },
  {
    value: '放射体检',
    label: '放射体检'
  },
  {
    value: '从业体检',
    label: '从业体检'
  }
]
</script>

<style lang="scss" scoped>
.top {
  display: flex;
  .form-item {
    margin-left: 5px;
  }
}
</style>
