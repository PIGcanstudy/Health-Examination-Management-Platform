<template>
  <!-- 列表名称区域 -->
  <el-card class="top">
    <div class="list-name">
      <span>人员列表</span>
    </div>
  </el-card>

  <!-- 主体部分 -->
  <el-card class="body" shadow="hover">
    <!-- 表单空间区域 -->
    <div class="form-area">
      <el-form :model="form">
        <el-form-item>
          <el-radio-group v-model="form.resource" style="margin-right: auto">
            <el-radio label="已检" />
            <el-radio label="未检" />
          </el-radio-group>
          <el-switch v-model="slider" width="60" inline-prompt active-text="复查" inactive-text="非复"></el-switch>
        </el-form-item>
        <el-form-item>
          <el-row clearable>
            <el-date-picker v-model="form.startDate" type="date" placeholder="开始时间" width="100" />
            <span>~</span>
            <el-date-picker v-model="form.endDate" type="date" placeholder="结束时间" width="100%" />
          </el-row>
        </el-form-item>
        <el-form-item>
          <el-input v-model="form.name" placeholder="请输入姓名" clearable />
        </el-form-item>
        <el-form-item>
          <el-input v-model="form.serialNumber" placeholder="请输入体检编号" clearable />
        </el-form-item>
        <el-form-item>
          <el-input v-model="form.workplace" placeholder="请输入单位名称" clearable />
        </el-form-item>
        <el-form-item>
          <el-button type="primary" @click="onSubmit">查询</el-button>
          <el-button plain @click="resetForm">重置</el-button>
          <el-button type="text"
            >展开<el-icon collapse-close-icon collapse-open-icon><ArrowDown /></el-icon>
          </el-button>
        </el-form-item>
      </el-form>
    </div>

    <!-- 表格数据区域 -->
    <div class="table-area">
      <el-table
        ref="multipleTableRef"
        v-loading="loading"
        :data="tableData"
        :show-header="false"
        highlight-current-row
        @select="select"
        @selection-change="handleSelectionChange"
        @row-click="selectClick"
      >
        <el-table-column type="selection" width="50" />
        <el-table-column property="name">
          <!-- <template>{{ scope.row.name }}</template> -->
        </el-table-column>
        <el-table-column property="gender">
          <!-- <template>{{ scope.row.gender }}</template> -->
        </el-table-column>
        <el-table-column property="age">
          <!-- <template>{{ scope.row.age }}</template> -->
        </el-table-column>
        <el-table-column>
          <el-tag class="tag2" type="success">健</el-tag>
          <el-tag class="tag2" type="danger">零</el-tag>
        </el-table-column>
      </el-table>
    </div>

    <!-- 分页区域 -->
    <el-pagination
      v-model:current-page="currentPage"
      v-model:page-size="pageSize"
      :page-sizes="[10]"
      layout="prev, jumper, pager, next, "
      :total="50"
      style="justify-content: center; margin-top: 30px"
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
    />
  </el-card>
</template>

<script setup>
import { ref } from 'vue'
import { ArrowDown } from '@element-plus/icons-vue'

// 滑块开关逻辑
const slider = ref(true)

// 表单验证逻辑
const form = ref({
  name: '',
  serialNumber: '',
  startDate: '',
  endDate: '',
  resource: ''
})

const onSubmit = () => {
  console.log('submit')
}
const resetForm = () => {
  console.log('reset')
}

// 页面加载逻辑
const loading = ref(false)

// 表格数据存放区域
const tableData = [
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '健'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  },
  {
    name: '张楠楠',
    gender: '女',
    age: '30',
    tags: '零'
  }
]
const multipleTableRef = ref()
const multipleSelection = ref([])
const handleSelectionChange = (val) => {
  multipleSelection.value = val
}
const select = (selection, row) => {
  // 清除 所有勾选项
  multipleTableRef.value.clearSelection()
  // 当表格数据都没有被勾选的时候 就返回
  // 主要用于将当前勾选的表格状态清除
  if (selection.length == 0) return
  multipleTableRef.value.toggleRowSelection(row, true)
}

// 控制单选——table选择项发生变化时
const selectClick = (row) => {
  const selectData = multipleSelection.value
  multipleTableRef.value.clearSelection()
  if (selectData.length == 1) {
    console.log('有值时')

    selectData.forEach((item) => {
      // 判断 如果当前的一行被勾选, 再次点击的时候就会取消选中
      if (item == row) {
        multipleTableRef.value.toggleRowSelection(row, false)
      }
      // 不然就让当前的一行勾选
      else {
        multipleTableRef.value.toggleRowSelection(row, true)
      }
    })
  } else {
    multipleTableRef.value.toggleRowSelection(row, true)
  }
}

// 分页逻辑
const currentPage = ref(1)
const pageSize = ref(10)
const handleSizeChange = (size) => {
  console.log('当前每页条数', size)
}
const handleCurrentChange = (page) => {
  console.log('页码发生变化', page)
}
</script>

<style lang="scss" scoped>
.top {
  text-align: center;
  background-color: rgb(240, 250, 255);

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}
</style>
