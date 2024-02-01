<!-- 部门管理 -->
<template>
  <el-container>
    <el-header>
  <el-button >添加子部门</el-button>
  <el-button >添加一级部门</el-button>
  <el-button >批量删除</el-button>
  <el-button >刷新</el-button>
  <el-switch v-model="value1" witdh="50px" inline-prompt active-text="级联" inactive-text="不级联" />
  </el-header>
  <el-container>
    <el-aside>
      <div>当前选择编辑</div>
    </el-aside>
    <el-main>
      <div display:column>
      <div display:flex class="text">上级部门<el-input v-model="input" class="input-1"/>
        <el-button @click="Selectdepartment">选择部门</el-button>
      </div>
      <div class="text">*部门名称 <el-input v-model="input" class="input-1"/></div>
      <div class="text">部门负责人 <el-input v-model="input" class="input-1"/>
        <el-button @click="Selectpeople1">选择用户</el-button></div>
        <div class="text">副负责人 <el-input v-model="input" class="input-1"/>
        <el-button @click="Selectpeople2">选择用户</el-button></div>
        <div class="text">*排序值 
          <el-popover placement="right" :width="200" trigger="hover" content="值越小越靠前，支持小数">
  <template #reference>
          <el-input-number v-model="num" :min="1" :max="10" @change="handleChange" /></template></el-popover>
        </div>
        <div>是否启用<el-switch v-model="value1" witdh="50px" inline-prompt active-text="启用" inactive-text="不启用" /></div>
      </div>
      <el-button>重置</el-button>
      </el-main>
  </el-container>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'

const value1 = ref(true)
const input = ref('')
const num = ref(1);
const handleChange = (value) => {
  num++;
  console.log(value);
};
</script>

<style lang="scss" scoped>
.input-1{
  width: 200px;
  line-height: 100px;
  margin: 10px;
}
.text{
  text-align: left;
}
</style>
