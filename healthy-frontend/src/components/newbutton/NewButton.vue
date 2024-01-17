<template>
  <el-card class="box-card">
    <template #header>
      <div class="card-header">
        <span>新增</span>
      </div>
    </template>
    <div class="column-1">单位名称 <el-input class="size" v-model="input" placeholder="请输入单位名称" /></div>
    <div class="column-2">体检类型</div>
    <el-select v-model="value" class="m-2" placeholder="Select" size="default" style="width: 150px">
      <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
    </el-select>
    <div class="column-1">统一社会信用代码 <el-input class="size" v-model="input" placeholder="请输入统一注册和信用代码" /></div>
    <div class="column-2">行业类型</div>
    <el-select v-model="value" class="m-2" placeholder="Select" size="default" style="width: 150px">
      <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
    </el-select>
    <div class="column-1">所属地区</div>
    <el-select v-model="value" class="m-2" placeholder="Select" size="default" style="width: 150px">
      <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
    </el-select>
    <div class="column-2">经济类型</div>
    <el-select v-model="value" class="m-2" placeholder="Select" size="default" style="width: 150px">
      <el-option class="option" />
    </el-select>
    <div class="column-1">单位注册地址 <el-input class="size" v-model="input" placeholder="请输入单位注册地址" /></div>
    <div class="column-2">企业规模</div>
    <el-select v-model="value" class="m-2" placeholder="Select" size="default" style="width: 150px">
      <el-option v-for="item in options" :key="item.value" :label="item.label" :value="item.value" />
    </el-select>
    <div class="column-1">体检联系人姓名 <el-input class="size" v-model="input" placeholder="请输入联系人姓名" /></div>

    <div class="column-2">体检联系人电话<el-input class="size" v-model="input" placeholder="请输入联系人电话 " /></div>
    <template #footer
      ><el-button class="button1" @click="closeCard">取消</el-button>
      <el-button class="button2" text>提交</el-button>
    </template>
  </el-card>
</template>
<script setup>
import { ref, onMounted } from 'vue'

const myCard = ref(null)

const closeCard = () => {
  if (myCard.value) {
    myCard.value.style.display = 'none'
  }
}

const options = [
  {
    value: 'Option1',
    label: 'Option1'
  },
  {
    value: 'Option2',
    label: 'Option2'
  },
  {
    value: 'Option3',
    label: 'Option3'
  },
  {
    value: 'Option4',
    label: 'Option4'
  },
  {
    value: 'Option5',
    label: 'Option5'
  }
]

// 如果需要在组件挂载后执行一些逻辑，可以使用 onMounted 钩子
onMounted(() => {
  console.log('已挂载')
})
</script>

<style scoped>
.card-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.text {
  font-size: 14px;
}

.item {
  margin-bottom: 18px;
  display: flex;
  justify-content: space-between;
  align-items: center;
}

.box-card {
  width: 800px;
  height: 800px;
}
.column-1,
.column-2 {
  display: inline-block;
  column-count: 2;
  text-align: left;
}
.card-footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
}
.button1 {
  position: absolute;
  top: 20px;
  left: 85%;
}
.button2 {
  position: absolute; /*或relative*/
  top: 20px;
  left: 90%;
}
.size {
  size: 20px;
}
</style>
